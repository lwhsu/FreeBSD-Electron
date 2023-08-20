--- third_party/blink/renderer/core/html/parser/html_document_parser_fastpath.cc.orig	2023-08-10 01:48:50 UTC
+++ third_party/blink/renderer/core/html/parser/html_document_parser_fastpath.cc
@@ -169,7 +169,11 @@ class HTMLFastPathParser {
   using Span = base::span<const Char>;
   using USpan = base::span<const UChar>;
   // 32 matches that used by HTMLToken::Attribute.
+#if defined(__clang__) && (__clang_major__ >= 16)
   typedef std::conditional<std::is_same_v<Char, UChar>,
+#else
+  typedef typename std::conditional<std::is_same_v<Char, UChar>,
+#endif
                            UCharLiteralBuffer<32>,
                            LCharLiteralBuffer<32>>::type LiteralBufferType;
   typedef UCharLiteralBuffer<32> UCharLiteralBufferType;
