.name "aff_tester1"

.comment "This champion is a tester for the aff function."

		ld		%49, r2
		aff		r2
		ld		%67, r2
		aff		r2
		ld		%111, r2
		aff		r2
		ld		%117, r2
		aff		r2
		ld		%99, r2
		aff		r2
		ld		%111, r2
		aff		r2
		ld		%117, r2
		aff		r2
		ld		%32, r2
		aff		r2
		ld		%33, r2
		aff		r2
		ld		%10, r2
		aff		r2

label:	xor		%42, %42, r3
		zjmp	%:label
