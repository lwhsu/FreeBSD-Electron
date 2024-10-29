--- ui/ozone/common/features.cc.orig	2024-10-16 21:32:40 UTC
+++ ui/ozone/common/features.cc
@@ -30,7 +30,7 @@ BASE_FEATURE(kWaylandFractionalScaleV1,
 // enabled.
 BASE_FEATURE(kWaylandFractionalScaleV1,
              "WaylandFractionalScaleV1",
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -42,7 +42,7 @@ BASE_FEATURE(kWaylandXdgToplevelDrag,
 // protocol is supported.
 BASE_FEATURE(kWaylandXdgToplevelDrag,
              "WaylandXdgToplevelDrag",
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
