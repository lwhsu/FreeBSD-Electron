--- electron/spec/api-process-spec.ts.orig	2024-10-09 13:53:06 UTC
+++ electron/spec/api-process-spec.ts
@@ -46,7 +46,7 @@ describe('process module', () => {
       it('resolves promise successfully with valid data', async () => {
         const memoryInfo = await w.webContents.executeJavaScript('process.getProcessMemoryInfo()');
         expect(memoryInfo).to.be.an('object');
-        if (process.platform === 'linux' || process.platform === 'win32') {
+        if (process.platform === 'linux' || process.platform === 'win32' || process.platform === 'freebsd') {
           expect(memoryInfo.residentSet).to.be.a('number').greaterThan(0);
         }
         expect(memoryInfo.private).to.be.a('number').greaterThan(0);
@@ -145,7 +145,7 @@ describe('process module', () => {
       it('resolves promise successfully with valid data', async () => {
         const memoryInfo = await process.getProcessMemoryInfo();
         expect(memoryInfo).to.be.an('object');
-        if (process.platform === 'linux' || process.platform === 'win32') {
+        if (process.platform === 'linux' || process.platform === 'win32' || process.platform === 'freebsd') {
           expect(memoryInfo.residentSet).to.be.a('number').greaterThan(0);
         }
         expect(memoryInfo.private).to.be.a('number').greaterThan(0);
