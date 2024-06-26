--- src/main/windows/mainWindow.ts.orig	2024-06-13 12:45:42 UTC
+++ src/main/windows/mainWindow.ts
@@ -91,7 +91,7 @@ export class MainWindow extends EventEmitter {
         });
         log.debug('main window options', windowOptions);
 
-        if (process.platform === 'linux') {
+        if (process.platform === 'linux' || process.platform === 'freebsd') {
             windowOptions.icon = path.join(path.resolve(app.getAppPath(), 'assets'), 'linux', 'app_icon.png');
         }
 
@@ -138,7 +138,7 @@ export class MainWindow extends EventEmitter {
             // This is mostly a fix for Windows 11 snapping
             this.win.on('moved', this.onResized);
         }
-        if (process.platform === 'linux') {
+        if (process.platform === 'linux' || process.platform === 'freebsd') {
             this.win.on('resize', this.onResize);
         }
         this.win.webContents.on('before-input-event', this.onBeforeInputEvent);
@@ -197,7 +197,7 @@ export class MainWindow extends EventEmitter {
         // Workaround for linux maximizing/minimizing, which doesn't work properly because of these bugs:
         // https://github.com/electron/electron/issues/28699
         // https://github.com/electron/electron/issues/28106
-        if (process.platform === 'linux') {
+        if (process.platform === 'linux' || process.platform === 'freebsd') {
             const size = this.win.getSize();
             return {...this.win.getContentBounds(), width: size[0], height: size[1]};
         }
@@ -311,7 +311,7 @@ export class MainWindow extends EventEmitter {
 
     private onFocus = () => {
         // Only add shortcuts when window is in focus
-        if (process.platform === 'linux') {
+        if (process.platform === 'linux' || process.platform === 'freebsd') {
             globalShortcut.registerAll(ALT_MENU_KEYS, () => {
                 // do nothing because we want to supress the menu popping up
             });
@@ -356,7 +356,7 @@ export class MainWindow extends EventEmitter {
             }
             switch (process.platform) {
             case 'win32':
-            case 'linux':
+            case 'linux': case 'freebsd':
                 if (Config.minimizeToTray) {
                     if (Config.alwaysMinimize) {
                         hideWindow(this.win);
