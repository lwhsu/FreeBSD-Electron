# Notes for port maintainer
#
# Before copying package.json and yarn.lock to ${PKGJSONSDIR}, do the following steps:
# 1. Remove sharp from devDependencies in ${WRKSRC}/packages/lib
#    $ corepack yarn remove --mode=skip-build sharp
# 2. Remove sharp from devDependencies in ${WRKSRC}/packages/app-mobile
#    $ corepack yarn remove --mode=skip-build sharp
# 3. Add node-addon-api and node-gyp to devDependencies in ${WRKSRC}/packages/tools
#    $ corepack yarn add --dev --mode=skip-build node-addon-api node-gyp

PORTNAME=	joplin
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.24
CATEGORIES=	deskutils
PKGNAMESUFFIX=	-desktop
DISTFILES=	${DEFAULT_PLUGINS_NODE_MODULES_FILE}:prefetch

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Note taking and to-do application with synchronisation capabilities
WWW=		https://joplinapp.org

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

FETCH_DEPENDS=	npm${NODEJS_SUFFIX}>0:www/npm${NODEJS_SUFFIX}
BUILD_DEPENDS=	7zz:archivers/7-zip \
		git:devel/git \
		rsync:net/rsync \
		npm${NODEJS_SUFFIX}>0:www/npm${NODEJS_SUFFIX}
LIB_DEPENDS=	libvips.so:graphics/vips \
		libsecret-1.so:security/libsecret

USES=		cargo electron:29 gmake localbase:ldflags nodejs:20,build \
		python:build

USE_GITHUB=	yes
GH_ACCOUNT=	laurent22
GH_TUPLE=	rollup:rollup:v4.9.1:rollup/rollup
# See ${WRKSRC}/packages/default-plugins/pluginRepositories.json for GH_TUPLEs for default plugins
GH_TUPLE+=	JackGruber:joplin-plugin-backup:5ba57c18ac0f24f20832f012e015a080b138f0c4:joplin_plugin_backup/packages/default-plugins/plugin-sources/io.github.jackgruber.backup

CARGO_CARGOTOML=${WRKSRC}/rollup/rust/Cargo.toml
CARGO_CARGOLOCK=${WRKSRC}/rollup/rust/Cargo.lock
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no

BINARY_ALIAS=	python3=${PYTHON_CMD}

SUB_FILES=	${PORTNAME}${PKGNAMESUFFIX}

BUILD_WRKSRC=	${WRKSRC}/packages/app-desktop
TEST_WRKSRC=	${WRKSRC}/packages/app-desktop

PORTDOCS=	README.md SECURITY.md

OPTIONS_DEFINE=	DOCS

USE_ELECTRON=	npm:yarn2 appbuilder prefetch extract build:builder

DEFAULT_PLUGINS_NODE_MODULES_FILE=	${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSION}-default-plugins-node-modules${EXTRACT_SUFX}

pre-fetch:
	@if [ ! -f ${DISTDIR}/${DEFAULT_PLUGINS_NODE_MODULES_FILE} ]; then \
		${ECHO_MSG} "===>  Prefetching and archiving node modules for default plugins"; \
		${MKDIR} ${WRKDIR}/node-modules-cache; \
		${CP} -R ${FILESDIR}/default-plugins/* ${WRKDIR}/node-modules-cache; \
		for dir in `${FIND} ${FILESDIR}/default-plugins -type d -depth 1 -print | ${SED} -e 's|${FILESDIR}/default-plugins||'`; do \
			cd ${WRKDIR}/node-modules-cache/$${dir} && \
			${SETENV} HOME=${WRKDIR} XDG_CACHE_HOME=${WRKDIR}/.cache \
				npm ci --ignore-scripts --no-progress --no-audit --no-fund; \
			${RM} package.json package-lock.json; \
		done; \
		cd ${WRKDIR} && \
		${MTREE_CMD} -cbnSp node-modules-cache | ${MTREE_CMD} -C | ${SED} \
			-e 's:time=[0-9.]*:time=${PREFETCH_TIMESTAMP}.000000000:' \
			-e 's:\([gu]id\)=[0-9]*:\1=0:g' \
			-e 's:flags=.*:flags=none:' \
			-e 's:^\.:./node-modules-cache:' > node-modules-cache.mtree && \
		${SETENV} LANG=en_US.UTF-8 LC_ALL=en_US.UTF-8 \
			${TAR} -cz --options 'gzip:!timestamp' \
			-f ${DISTDIR}/${DEFAULT_PLUGINS_NODE_MODULES_FILE} @node-modules-cache.mtree; \
		${RM} -r ${WRKDIR}; \
	fi

post-extract:
	@${ECHO_MSG} "===>  Moving prefetched node modules for default plugins to ${WRKSRC}"
	@for dir in `${FIND} ${WRKDIR}/node-modules-cache -type d -depth 1 -print | ${SED} -e 's|${WRKDIR}/node-modules-cache||'`; do \
		${MV} ${WRKDIR}/node-modules-cache/$${dir}/node_modules \
			${WRKSRC}/packages/default-plugins/plugin-sources/$${dir}; \
	done

post-patch:
	@${RM} -r ${WRKSRC}/packages/app-cli \
		${WRKSRC}/packages/app-clipper

pre-build:
	cd ${WRKSRC}/rollup/rust && \
		${SETENV} ${MAKE_ENV} ${CARGO_ENV} ${CARGO} build --release --verbose --verbose
	${CP} ${CARGO_TARGET_DIR}/release/libbindings_napi.so \
		${WRKSRC}/packages/turndown/node_modules/rollup/dist/rollup.freebsd-${ELECTRON_ARCH}.node
	@${MKDIR} ${WRKSRC}/packages/app-desktop/node_modules/7zip-bin/freebsd/${ELECTRON_ARCH}
	${CP} ${LOCALBASE}/bin/7zz \
		${WRKSRC}/packages/app-desktop/node_modules/7zip-bin/freebsd/${ELECTRON_ARCH}/7za
	cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${NODEJS_REBUILD_ENV} \
		yarn rebuild
	cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${ELECTRON_REBUILD_ENV} \
		yarn exec electron-rebuild --force-abi 122

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}${PKGNAMESUFFIX}.desktop ${STAGEDIR}${DESKTOPDIR}
.for size in 16 24 32 48 72 96 128 144 256 512 1024
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}x${size}/apps
	${INSTALL_DATA} ${BUILD_WRKSRC}/build/icons/${size}x${size}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}x${size}/apps/${PORTNAME}.png
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${BUILD_WRKSRC}/dist/${ELECTRON_BUILDER_APP_OUT_DIR} && \
		${COPYTREE_SHARE} resources ${STAGEDIR}${DATADIR}
	${FIND} ${STAGEDIR}${DATADIR}/resources -type f -exec ${FILE} {} ';' | \
		${GREP} 'ELF.*FreeBSD' | ${AWK} -F ': ' '{print $$1}' | ${XARGS} ${STRIP_CMD}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

do-test:
	cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} yarn run test

.include <bsd.port.mk>
