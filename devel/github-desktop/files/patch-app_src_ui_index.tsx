--- app/src/ui/index.tsx.orig	2024-06-02 17:20:33 UTC
+++ app/src/ui/index.tsx
@@ -2,7 +2,7 @@ import * as ReactDOM from 'react-dom'
 
 import * as React from 'react'
 import * as ReactDOM from 'react-dom'
-import * as Path from 'path'
+// import * as Path from 'path'
 import { App } from './app'
 import {
   Dispatcher,
@@ -88,7 +88,7 @@ enableSourceMaps()
 
 // Tell dugite where to find the git environment,
 // see https://github.com/desktop/dugite/pull/85
-process.env['LOCAL_GIT_DIRECTORY'] = Path.resolve(__dirname, 'git')
+// process.env['LOCAL_GIT_DIRECTORY'] = Path.resolve(__dirname, 'git')
 
 // Ensure that dugite infers the GIT_EXEC_PATH
 // based on the LOCAL_GIT_DIRECTORY env variable
