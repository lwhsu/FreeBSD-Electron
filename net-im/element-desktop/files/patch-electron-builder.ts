--- electron-builder.ts.orig	2025-04-23 19:15:41.000000000 +0800
+++ electron-builder.ts	2025-04-28 15:02:02.357570000 +0800
@@ -90,9 +90,9 @@
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
