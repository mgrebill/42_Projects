.name "sti_tester1"

.comment "This champion is a tester for the sti function with REG, REG, DIR.
			//
			Print r3 content (*)."

			ld %42, r2
			ld %8, r4
			sti r2, r4, %0
			ld %0, r3
			aff r3

loop:		and %42, %0, r2
			zjmp %:loop
