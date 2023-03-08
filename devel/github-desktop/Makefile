PORTNAME=	github-desktop
DISTVERSIONPREFIX=	release-
DISTVERSION=	3.2.0
DISTVERSIONSUFFIX=	-linux1
CATEGORIES=	devel
MASTER_SITES=	KERNEL_ORG/software/scm/git:git
DISTFILES=	${PREFETCH_FILE}:prefetch \
		git-${GIT_VER}${EXTRACT_SUFX}:git

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Focus on what matters instead of fighting with Git
WWW=		https://github.com/shiftkey/desktop

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libatk-bridge-2.0.so:accessibility/at-spi2-core \
		libsnappy.so:archivers/snappy \
		libFLAC.so:audio/flac \
		libopus.so:audio/opus \
		libsndio.so:audio/sndio \
		libdbus-1.so:devel/dbus \
		libicui18n.so:devel/icu \
		libevent.so:devel/libevent \
		libpci.so:devel/libpci \
		libnspr4.so:devel/nspr \
		libdrm.so:graphics/libdrm \
		libpng.so:graphics/png \
		libwayland-egl.so:graphics/wayland \
		libwebp.so:graphics/webp \
		libopenh264.so:multimedia/openh264 \
		libcups.so:print/cups \
		libharfbuzz.so:print/harfbuzz \
		libnss3.so:security/nss \
		libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libxkbcommon.so:x11/libxkbcommon \
		libxshmfence.so:x11/libxshmfence

USES=		desktop-file-utils gettext-runtime gl gmake gnome electron:22 \
		iconv jpeg localbase:ldflags nodejs:16,build perl5 python \
		shebangfix ssl xorg

USE_GITHUB=	yes
GH_ACCOUNT=	shiftkey
GH_PROJECT=	desktop
GH_TUPLE=	github:gemoji:50865e8895c54037bf06c4c1691aa925d030a59d:gemoji/gemoji \
		github:gitignore:e89e04390435f1e7628740d7b4ce1fe65ac218fd:gitignore/app/static/common/gitignore \
		github:choosealicense.com:d4edd14487305505af3eab98e364b9d2a86c5eec:choosealicense/app/static/common/choosealicense.com

USE_XORG=	x11 xcb xcomposite xdamage xext xfixes xi xrandr xrender xtst
USE_GL=		gbm gl
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 libxml2 libxslt pango

SHEBANG_FILES=	../git-${GIT_VER}/git-p4.py \
		../git-${GIT_VER}/templates/hooks--fsmonitor-watchman.sample

USE_ELECTRON=	npm:yarn,fetch,extract,build

.include <bsd.port.pre.mk>

GIT_VER=	2.39.2
PREFETCH_FILE=	${PKGNAME}-node-modules${EXTRACT_SUFX}
PREFETCH_TIMESTAMP=	1678187470
UPSTREAM_ELECTRON_VER!=		${GREP} -e 'resolved.*/electron/' ${PKGJSONSDIR}/yarn.lock | \
				${HEAD} -n 1 | ${AWK} -F- '{print $$NF}' | ${SED} -E 's/\.[a-z]+.*$$//'
ELECTRON_DOWNLOAD_URL=		https://github.com/electron/electron/releases/download/v${UPSTREAM_ELECTRON_VER}
ELECTRON_DOWNLOAD_URL_HASH!=	${SHA256} -q -s ${ELECTRON_DOWNLOAD_URL}
ELECTRON_DOWNLOAD_CACHE_DIR=	.cache/electron/${ELECTRON_DOWNLOAD_URL_HASH}
MAKE_ENV+=	CIRCLE_SHA1=f5f68928c2cae3a4dad4e9814681115c9d3ef834

pre-fetch:
	if [ ! -f ${DISTDIR}/${PREFETCH_FILE} ]; then \
		${MKDIR} ${WRKDIR}/node-modules-cache; \
		${ECHO_CMD} 'yarn-offline-mirror "./yarn-offline-cache"' >> \
			${WRKDIR}/node-modules-cache/.yarnrc; \
		${CP} -R ${PKGJSONSDIR}/* ${WRKDIR}/node-modules-cache; \
		cd ${WRKDIR}/node-modules-cache && \
		${SETENV} HOME=${WRKDIR} XDG_CACHE_HOME=${WRKDIR}/.cache \
			yarn --frozen-lockfile --ignore-scripts; \
		cd ${WRKDIR}/node-modules-cache/app && \
		${SETENV} HOME=${WRKDIR} XDG_CACHE_HOME=${WRKDIR}/.cache \
			yarn --frozen-lockfile --ignore-scripts; \
		${FIND} ${WRKDIR}/node-modules-cache -depth 1 -print | ${GREP} -v yarn-offline-cache | \
			${XARGS} ${RM} -r; \
		cd ${WRKDIR}/node-modules-cache && \
		${MTREE_CMD} -cbnSp yarn-offline-cache | ${MTREE_CMD} -C | ${SED} \
			-e 's:time=[0-9.]*:time=${PREFETCH_TIMESTAMP}.000000000:' \
			-e 's:\([gu]id\)=[0-9]*:\1=0:g' \
			-e 's:flags=.*:flags=none:' \
			-e 's:^\.:./yarn-offline-cache:' > node-modules-cache.mtree; \
		${SETENV} LANG=en_US.UTF-8 LC_ALL=en_US.UTF-8 \
			${TAR} -cz --options 'gzip:!timestamp' \
			-f ${DISTDIR}/${PREFETCH_FILE} @node-modules-cache.mtree; \
		${RM} -r ${WRKDIR}; \
	fi

post-extract:
.for f in package.json yarn.lock
	if [ -f ${WRKSRC}/${f} ]; then \
		${MV} -f ${WRKSRC}/${f} ${WRKSRC}/${f}.bak; \
	fi
	${CP} ${PKGJSONSDIR}/${f} ${WRKSRC}
.endfor
.for f in package.json yarn.lock
	if [ -f ${WRKSRC}/app/${f} ]; then \
		${MV} -f ${WRKSRC}/app/${f} ${WRKSRC}/app/${f}.bak; \
	fi
	${CP} ${PKGJSONSDIR}/app/${f} ${WRKSRC}/app
.endfor
	${ECHO_CMD} 'yarn-offline-mirror "../yarn-offline-cache"' >> ${WRKSRC}/.yarnrc
	cd ${WRKSRC} && ${SETENV} HOME=${WRKDIR} XDG_CACHE_HOME=${WRKDIR}/.cache \
		yarn --frozen-lockfile --ignore-scripts --offline
	cd ${WRKSRC}/app && ${SETENV} HOME=${WRKDIR} XDG_CACHE_HOME=${WRKDIR}/.cache \
		yarn --frozen-lockfile --ignore-scripts --offline

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/app/src/lib/editors/linux.ts
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/app/src/lib/shells/linux.ts

pre-build:
	${RM} -r ${WRKDIR}/electron-dist
	${MKDIR} ${WRKDIR}/electron-dist
	cd ${LOCALBASE}/share/electron${ELECTRON_VERSION} && \
		${TAR} -cf - . | ${TAR} -xf - -C ${WRKDIR}/electron-dist
	cd ${WRKDIR}/electron-dist && \
		${FIND} . -type f -perm ${BINMODE} -exec ${CHMOD} 755 {} ';'
	${MKDIR} ${WRKDIR}/${ELECTRON_DOWNLOAD_CACHE_DIR}
	cd ${WRKDIR}/electron-dist && \
		zip -q -r ${WRKDIR}/${ELECTRON_DOWNLOAD_CACHE_DIR}/electron-v${UPSTREAM_ELECTRON_VER}-linux-x64.zip .
	cd ${WRKDIR}/${ELECTRON_DOWNLOAD_CACHE_DIR} && \
		${SHA256} -r *.zip | \
		${SED} -e 's/ / */' > SHASUMS256.txt-${UPSTREAM_ELECTRON_VER}

do-build:
	cd ${WRKDIR}/git-${GIT_VER} && \
		./configure --prefix=${WRKSRC}/app/node_modules/dugite/git \
			--enable-pthreads=-pthread \
			--with-iconv=${LOCALBASE} \
			--without-tcltk && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} -j ${MAKE_JOBS_NUMBER} CC="${CCACHE_BIN} ${CC}" all strip && \
		${SETEMV} ${MAKE_ENV} ${MAKE_CMD} CC="${CCACHE_BIN} ${CC}" install
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} yarn compile:script
	cd ${WRKSRC}/app && ${SETENV} ${MAKE_ENV} ${ELECTRON_REBUILD_ENV} npm rebuild --no-progress
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} yarn build:prod

do-install:
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.desktop \
		${STAGEDIR}${PREFIX}/share/applications
.for size in 32 64 128 256 512 1024
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}x${size}/apps
	${INSTALL_DATA} ${WRKSRC}/app/static/linux/logos/${size}x${size}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}x${size}/apps/${PORTNAME}.png
.endfor
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd "${WRKSRC}/dist/GitHub Desktop-linux-x64" && \
		${TAR} -cf - . | ${TAR} -xf - -C ${STAGEDIR}${DATADIR}
	cd ${STAGEDIR}${DATADIR}/resources/app && \
		${FIND} . -type f -name '*.node' -exec ${STRIP_CMD} {} ';'
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/resources/app/desktop-trampoline/desktop-trampoline
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/resources/app/git/bin/scalar
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/resources/app/git/libexec/git-core/scalar
.for f in chromedriver mksnapshot v8_context_snapshot_generator
	${RM} ${STAGEDIR}${DATADIR}/${f}
.endfor
	${RM} -r ${STAGEDIR}${DATADIR}/gen
	${RM} -r ${STAGEDIR}${DATADIR}/node_headers
	${MV} -f ${STAGEDIR}${DATADIR}/"GitHub Desktop" ${STAGEDIR}${DATADIR}/${PORTNAME}
	${RLN} ${STAGEDIR}${DATADIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-test:
	cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} yarn test

.include <bsd.port.post.mk>