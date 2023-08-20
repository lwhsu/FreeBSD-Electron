--- third_party/boringssl/src/crypto/fipsmodule/aes/asm/aesni-x86_64.pl.orig	2023-08-10 01:51:10 UTC
+++ third_party/boringssl/src/crypto/fipsmodule/aes/asm/aesni-x86_64.pl
@@ -275,6 +275,7 @@ $code.=<<___;
 .align	16
 ${PREFIX}_encrypt:
 .cfi_startproc
+	_CET_ENDBR
 #ifdef BORINGSSL_DISPATCH_TEST
 .extern	BORINGSSL_function_hit
 	movb \$1,BORINGSSL_function_hit+1(%rip)
@@ -297,6 +298,7 @@ $code.=<<___;
 .align	16
 ${PREFIX}_decrypt:
 .cfi_startproc
+	_CET_ENDBR
 	movups	($inp),$inout0		# load input
 	mov	240($key),$rounds	# key->rounds
 ___
@@ -617,6 +619,7 @@ $code.=<<___;
 .align	16
 ${PREFIX}_ecb_encrypt:
 .cfi_startproc
+	_CET_ENDBR
 ___
 $code.=<<___ if ($win64);
 	lea	-0x58(%rsp),%rsp
@@ -1203,6 +1206,7 @@ $code.=<<___;
 .align	16
 ${PREFIX}_ctr32_encrypt_blocks:
 .cfi_startproc
+	_CET_ENDBR
 #ifdef BORINGSSL_DISPATCH_TEST
 	movb \$1,BORINGSSL_function_hit(%rip)
 #endif
@@ -1781,6 +1785,7 @@ $code.=<<___;
 .align	16
 ${PREFIX}_xts_encrypt:
 .cfi_startproc
+	_CET_ENDBR
 	lea	(%rsp),%r11			# frame pointer
 .cfi_def_cfa_register	%r11
 	push	%rbp
@@ -2264,6 +2269,7 @@ $code.=<<___;
 .align	16
 ${PREFIX}_xts_decrypt:
 .cfi_startproc
+	_CET_ENDBR
 	lea	(%rsp),%r11			# frame pointer
 .cfi_def_cfa_register	%r11
 	push	%rbp
@@ -2782,6 +2788,7 @@ $code.=<<___;
 .align	16
 ${PREFIX}_cbc_encrypt:
 .cfi_startproc
+	_CET_ENDBR
 	test	$len,$len		# check length
 	jz	.Lcbc_ret
 
@@ -3331,6 +3338,7 @@ $code.=<<___;
 .align	16
 ${PREFIX}_set_decrypt_key:
 .cfi_startproc
+	_CET_ENDBR
 	.byte	0x48,0x83,0xEC,0x08	# sub rsp,8
 .cfi_adjust_cfa_offset	8
 	call	__aesni_set_encrypt_key
@@ -3403,6 +3411,7 @@ $code.=<<___;
 ${PREFIX}_set_encrypt_key:
 __aesni_set_encrypt_key:
 .cfi_startproc
+	_CET_ENDBR
 #ifdef BORINGSSL_DISPATCH_TEST
 	movb \$1,BORINGSSL_function_hit+3(%rip)
 #endif
