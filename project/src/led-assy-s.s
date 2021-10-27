	.arch msp430g2553
	.p2align 1,0
	.text

	.global alternate_leds
	.extern P1OUT

alternate_leds:
	cmp #500, r12
	jnc red_on
	bis.b #64, &P1OUT
	bis.b #0, &P1OUT
	pop r0

red_on:
	cmp #250, r12
	jnc green_on
	bis.b #64 , &P1OUT
	and.b #~0, &P1OUT
	pop r0

green_on:
	cmp #125, r12
	jnc exit
	bis.b #0, &P1OUT
	and.b #~64, &P1OUT
	pop r0

exit:
	pop r0
