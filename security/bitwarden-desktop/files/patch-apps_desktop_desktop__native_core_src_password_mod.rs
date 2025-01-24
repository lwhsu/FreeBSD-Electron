--- apps/desktop/desktop_native/core/src/password/mod.rs.orig	2025-01-23 11:12:57 UTC
+++ apps/desktop/desktop_native/core/src/password/mod.rs
@@ -1,5 +1,5 @@
 #[allow(clippy::module_inception)]
-#[cfg_attr(target_os = "linux", path = "unix.rs")]
+#[cfg_attr(any(target_os = "linux", target_os = "freebsd"), path = "unix.rs")]
 #[cfg_attr(target_os = "windows", path = "windows.rs")]
 #[cfg_attr(target_os = "macos", path = "macos.rs")]
 mod password;
