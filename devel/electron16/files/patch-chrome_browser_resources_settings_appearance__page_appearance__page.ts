--- chrome/browser/resources/settings/appearance_page/appearance_page.ts.orig	2021-11-19 04:25:09 UTC
+++ chrome/browser/resources/settings/appearance_page/appearance_page.ts
@@ -144,7 +144,7 @@ class SettingsAppearancePageElement extends SettingsAp
             'prefs.autogenerated.theme.policy.color.controlledBy)',
       },
 
-      // <if expr="is_linux and not chromeos and not lacros">
+      // <if expr="is_posix and not chromeos and not lacros">
       /**
        * Whether to show the "Custom Chrome Frame" setting.
        */
@@ -166,7 +166,7 @@ class SettingsAppearancePageElement extends SettingsAp
       'themeChanged_(' +
           'prefs.extensions.theme.id.value, useSystemTheme_, isForcedTheme_)',
 
-      // <if expr="is_linux and not chromeos">
+      // <if expr="is_posix and not chromeos">
       // NOTE: this pref only exists on Linux.
       'useSystemThemePrefChanged_(prefs.extensions.theme.use_system.value)',
       // </if>
@@ -185,7 +185,7 @@ class SettingsAppearancePageElement extends SettingsAp
   private showReaderModeOption_: boolean;
   private isForcedTheme_: boolean;
 
-  // <if expr="is_linux and not chromeos and not lacros">
+  // <if expr="is_posix and not chromeos and not lacros">
   private showCustomChromeFrame_: boolean;
   // </if>
 
@@ -263,7 +263,7 @@ class SettingsAppearancePageElement extends SettingsAp
     this.appearanceBrowserProxy_.useDefaultTheme();
   }
 
-  // <if expr="is_linux and not chromeos">
+  // <if expr="is_posix and not chromeos">
   private useSystemThemePrefChanged_(useSystemTheme: boolean) {
     this.useSystemTheme_ = useSystemTheme;
   }
@@ -324,10 +324,10 @@ class SettingsAppearancePageElement extends SettingsAp
     }
 
     let i18nId;
-    // <if expr="is_linux and not chromeos and not lacros">
+    // <if expr="is_posix and not chromeos and not lacros">
     i18nId = useSystemTheme ? 'systemTheme' : 'classicTheme';
     // </if>
-    // <if expr="not is_linux or chromeos or lacros">
+    // <if expr="not is_posix or chromeos or lacros">
     i18nId = 'chooseFromWebStore';
     // </if>
     this.themeSublabel_ = this.i18n(i18nId);
