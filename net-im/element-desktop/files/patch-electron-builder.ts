--- electron-builder.ts.orig	2025-02-11 14:42:27 UTC
+++ electron-builder.ts
@@ -90,9 +90,9 @@ const config: Omit<Writable<Configuration>, "electronF
         loadBrowserProcessSpecificV8Snapshot: false,
         enableEmbeddedAsarIntegrityValidation: true,
     },
-    afterPack: async (context: AfterPackContext) => {
+    /* afterPack: async (context: AfterPackContext) => {
         await injectAsarIntegrity(context);
-    },
+    }, */
     files: [
         "package.json",
         {
