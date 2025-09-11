MCUCR  = (1<<ISC00)|(1<<ISC01); // rising INT0
GICR | = (1<<INT0); // int 0 enable

MCUCR| = (1<<ISC10); // high logic  INT1
GICR | = (1<<INT1); // int 1 enable


sei();

ISR(INT0_vect)
    {

    }

ISR(INT1_vect)
    {

    }


main(){


    /*

    if (GIFR & (1U << INTF0)) { }
    // flag rising

    */

    }
