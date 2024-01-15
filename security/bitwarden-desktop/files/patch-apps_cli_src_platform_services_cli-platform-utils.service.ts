--- apps/cli/src/platform/services/cli-platform-utils.service.ts.orig	2024-01-09 15:12:51 UTC
+++ apps/cli/src/platform/services/cli-platform-utils.service.ts
@@ -79,7 +79,7 @@ export class CliPlatformUtilsService implements Platfo
   }
 
   launchUri(uri: string, options?: any): void {
-    if (process.platform === "linux") {
+    if (process.platform === "linux" || process.platform === "freebsd") {
       child_process.spawnSync("xdg-open", [uri]);
     } else {
       open(uri);
