--- ui/gfx/font_render_params.h.orig	2024-02-21 00:21:15 UTC
+++ ui/gfx/font_render_params.h
@@ -118,7 +118,7 @@ GFX_EXPORT FontRenderParams GetFontRenderParams(
     const FontRenderParamsQuery& query,
     std::string* family_out);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Clears GetFontRenderParams()'s cache. Intended to be called by tests that are
 // changing Fontconfig's configuration.
 GFX_EXPORT void ClearFontRenderParamsCacheForTest();
@@ -128,7 +128,7 @@ GFX_EXPORT float GetFontRenderParamsDeviceScaleFactor(
 GFX_EXPORT float GetFontRenderParamsDeviceScaleFactor();
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 // Sets the device scale factor for FontRenderParams to decide
 // if it should enable subpixel positioning.
 GFX_EXPORT void SetFontRenderParamsDeviceScaleFactor(
