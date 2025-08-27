	.file	"practice.cpp"
	.section .rdata,"dr"
__ZStL19piecewise_construct:
	.space 1
.lcomm __ZStL8__ioinit,1,1
	.section	.text$_ZN5ArrayC2Ei,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5ArrayC2Ei
	.def	__ZN5ArrayC2Ei;	.scl	2;	.type	32;	.endef
__ZN5ArrayC2Ei:
LFB1446:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	$__ZTV5Array+8, %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	8(%ebp), %eax
	cmpl	$536870911, %eax
	ja	L2
	sall	$2, %eax
	jmp	L4
L2:
	call	___cxa_throw_bad_array_new_length
L4:
	movl	%eax, (%esp)
	call	__Znaj
	movl	%eax, %edx
	movl	-12(%ebp), %eax
	movl	%edx, 8(%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1446:
	.section	.text$_ZN5ArrayD2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5ArrayD2Ev
	.def	__ZN5ArrayD2Ev;	.scl	2;	.type	32;	.endef
__ZN5ArrayD2Ev:
LFB1449:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	$__ZTV5Array+8, %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	-12(%ebp), %eax
	movl	8(%eax), %eax
	testl	%eax, %eax
	je	L6
	movl	-12(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdaPv
L6:
	movl	-12(%ebp), %eax
	movl	$0, 8(%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1449:
	.section	.text$_ZN5ArrayD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5ArrayD1Ev
	.def	__ZN5ArrayD1Ev;	.scl	2;	.type	32;	.endef
__ZN5ArrayD1Ev:
LFB1450:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	$__ZTV5Array+8, %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	-12(%ebp), %eax
	movl	8(%eax), %eax
	testl	%eax, %eax
	je	L8
	movl	-12(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, (%esp)
	call	__ZdaPv
L8:
	movl	-12(%ebp), %eax
	movl	$0, 8(%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1450:
	.section	.text$_ZN5ArrayD0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5ArrayD0Ev
	.def	__ZN5ArrayD0Ev;	.scl	2;	.type	32;	.endef
__ZN5ArrayD0Ev:
LFB1451:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5ArrayD1Ev
	movl	$12, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPvj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1451:
	.section	.text$_ZN5Array6AcceptEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5Array6AcceptEv
	.def	__ZN5Array6AcceptEv;	.scl	2;	.type	32;	.endef
__ZN5Array6AcceptEv:
LFB1456:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	$0, -12(%ebp)
L12:
	movl	-28(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-12(%ebp), %eax
	jle	L13
	movl	-28(%ebp), %eax
	movl	8(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	%eax, (%esp)
	movl	$__ZSt3cin, %ecx
	call	__ZNSirsERi
	subl	$4, %esp
	addl	$1, -12(%ebp)
	jmp	L12
L13:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1456:
	.section .rdata,"dr"
LC0:
	.ascii " \0"
	.section	.text$_ZNK5Array7DisplayEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK5Array7DisplayEv
	.def	__ZNK5Array7DisplayEv;	.scl	2;	.type	32;	.endef
__ZNK5Array7DisplayEv:
LFB1457:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	$0, -12(%ebp)
L16:
	movl	-28(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-12(%ebp), %eax
	jle	L15
	movl	-28(%ebp), %eax
	movl	8(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	movl	$__ZSt4cout, %ecx
	call	__ZNSolsEi
	subl	$4, %esp
	movl	$LC0, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	addl	$1, -12(%ebp)
	jmp	L16
L15:
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)
	movl	$__ZSt4cout, %ecx
	call	__ZNSolsEPFRSoS_E
	subl	$4, %esp
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1457:
	.section	.text$_ZN9ArrayDemoC1Ei,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9ArrayDemoC1Ei
	.def	__ZN9ArrayDemoC1Ei;	.scl	2;	.type	32;	.endef
__ZN9ArrayDemoC1Ei:
LFB1460:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN5ArrayC2Ei
	subl	$4, %esp
	movl	$__ZTV9ArrayDemo+8, %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1460:
	.section	.text$_ZN9ArrayDemo17findSecondLargestEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9ArrayDemo17findSecondLargestEv
	.def	__ZN9ArrayDemo17findSecondLargestEv;	.scl	2;	.type	32;	.endef
__ZN9ArrayDemo17findSecondLargestEv:
LFB1461:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$20, %esp
	movl	%ecx, -20(%ebp)
	movl	-20(%ebp), %eax
	movl	8(%eax), %eax
	movl	(%eax), %eax
	movl	%eax, -4(%ebp)
	movl	$-1, -8(%ebp)
	movl	$0, -12(%ebp)
L22:
	movl	-20(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	-12(%ebp), %eax
	jle	L19
	movl	-20(%ebp), %eax
	movl	8(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	(%eax), %eax
	cmpl	-4(%ebp), %eax
	jle	L20
	movl	-4(%ebp), %eax
	movl	%eax, -8(%ebp)
	movl	-20(%ebp), %eax
	movl	8(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, -4(%ebp)
	jmp	L21
L20:
	movl	-20(%ebp), %eax
	movl	8(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	(%eax), %eax
	cmpl	-4(%ebp), %eax
	jge	L21
	movl	-20(%ebp), %eax
	movl	8(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	(%eax), %eax
	cmpl	-8(%ebp), %eax
	jle	L21
	movl	-20(%ebp), %eax
	movl	8(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, -8(%ebp)
L21:
	addl	$1, -12(%ebp)
	jmp	L22
L19:
	movl	-8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1461:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC1:
	.ascii "Enter size of array: \0"
LC2:
	.ascii "Enter elements:\12\0"
LC3:
	.ascii "Array elements:\12\0"
LC4:
	.ascii "Second largest element is :\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB1462:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1462
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x78,0x6
	.cfi_escape 0x10,0x3,0x2,0x75,0x7c
	subl	$48, %esp
	call	___main
	movl	$LC1, 4(%esp)
	movl	$__ZSt4cout, (%esp)
LEHB0:
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	movl	$__ZSt3cin, %ecx
	call	__ZNSirsERi
	subl	$4, %esp
	movl	-16(%ebp), %edx
	leal	-28(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9ArrayDemoC1Ei
LEHE0:
	subl	$4, %esp
	movl	$LC2, 4(%esp)
	movl	$__ZSt4cout, (%esp)
LEHB1:
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leal	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5Array6AcceptEv
	movl	$LC3, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leal	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK5Array7DisplayEv
	leal	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN9ArrayDemo17findSecondLargestEv
	movl	%eax, -12(%ebp)
	movl	$LC4, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%eax, %edx
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZNSolsEi
	subl	$4, %esp
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)
	movl	%eax, %ecx
	call	__ZNSolsEPFRSoS_E
LEHE1:
	subl	$4, %esp
	movl	$0, %ebx
	leal	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN9ArrayDemoD1Ev
	movl	%ebx, %eax
	jmp	L28
L27:
	movl	%eax, %ebx
	leal	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN9ArrayDemoD1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB2:
	call	__Unwind_Resume
LEHE2:
L28:
	leal	-8(%ebp), %esp
	popl	%ecx
	.cfi_restore 1
	.cfi_def_cfa 1, 0
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1462:
	.def	___gxx_personality_v0;	.scl	2;	.type	32;	.endef
	.section	.gcc_except_table,"w"
LLSDA1462:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1462-LLSDACSB1462
LLSDACSB1462:
	.uleb128 LEHB0-LFB1462
	.uleb128 LEHE0-LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB1-LFB1462
	.uleb128 LEHE1-LEHB1
	.uleb128 L27-LFB1462
	.uleb128 0
	.uleb128 LEHB2-LFB1462
	.uleb128 LEHE2-LEHB2
	.uleb128 0
	.uleb128 0
LLSDACSE1462:
	.text
	.globl	__ZTV9ArrayDemo
	.section	.rdata$_ZTV9ArrayDemo,"dr"
	.linkonce same_size
	.align 4
__ZTV9ArrayDemo:
	.long	0
	.long	__ZTI9ArrayDemo
	.long	__ZN9ArrayDemoD1Ev
	.long	__ZN9ArrayDemoD0Ev
	.section	.text$_ZN9ArrayDemoD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9ArrayDemoD1Ev
	.def	__ZN9ArrayDemoD1Ev;	.scl	2;	.type	32;	.endef
__ZN9ArrayDemoD1Ev:
LFB1896:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	$__ZTV9ArrayDemo+8, %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN5ArrayD2Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1896:
	.section	.text$_ZN9ArrayDemoD0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9ArrayDemoD0Ev
	.def	__ZN9ArrayDemoD0Ev;	.scl	2;	.type	32;	.endef
__ZN9ArrayDemoD0Ev:
LFB1897:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN9ArrayDemoD1Ev
	movl	$12, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPvj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1897:
	.globl	__ZTV5Array
	.section	.rdata$_ZTV5Array,"dr"
	.linkonce same_size
	.align 4
__ZTV5Array:
	.long	0
	.long	__ZTI5Array
	.long	__ZN5ArrayD1Ev
	.long	__ZN5ArrayD0Ev
	.globl	__ZTI9ArrayDemo
	.section	.rdata$_ZTI9ArrayDemo,"dr"
	.linkonce same_size
	.align 4
__ZTI9ArrayDemo:
	.long	__ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	__ZTS9ArrayDemo
	.long	__ZTI5Array
	.globl	__ZTS9ArrayDemo
	.section	.rdata$_ZTS9ArrayDemo,"dr"
	.linkonce same_size
	.align 4
__ZTS9ArrayDemo:
	.ascii "9ArrayDemo\0"
	.globl	__ZTI5Array
	.section	.rdata$_ZTI5Array,"dr"
	.linkonce same_size
	.align 4
__ZTI5Array:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTS5Array
	.globl	__ZTS5Array
	.section	.rdata$_ZTS5Array,"dr"
	.linkonce same_size
	.align 4
__ZTS5Array:
	.ascii "5Array\0"
	.text
	.def	___tcf_0;	.scl	3;	.type	32;	.endef
___tcf_0:
LFB1899:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitD1Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1899:
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
LFB1898:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$1, 8(%ebp)
	jne	L34
	cmpl	$65535, 12(%ebp)
	jne	L34
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitC1Ev
	movl	$___tcf_0, (%esp)
	call	_atexit
L34:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1898:
	.def	__GLOBAL__sub_I_main;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I_main:
LFB1900:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$65535, 4(%esp)
	movl	$1, (%esp)
	call	__Z41__static_initialization_and_destruction_0ii
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1900:
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I_main
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	___cxa_throw_bad_array_new_length;	.scl	2;	.type	32;	.endef
	.def	__Znaj;	.scl	2;	.type	32;	.endef
	.def	__ZdaPv;	.scl	2;	.type	32;	.endef
	.def	__ZdlPvj;	.scl	2;	.type	32;	.endef
	.def	__ZNSirsERi;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	__Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
