

//test cases code 

//TODO: write test cases 
  	//


    
  	//(int r, int c, int dir, int distance, char plotChar, int fgbg)
    //dir = 1 VERT ; dir = 0 HORIZ 
    //DIST pos - rightward or downard from (r,c)
    //DIST neg - leftward or upward from (r,c)
	// max row 20 
	// max column 30 

	//max out cases 
	//max out up from the top 
	//max out down from the bottom 
	//max out left hand side 
	//maxx out right hand side

	plotLine (15, 22, 1, 6, 'A')

	
	//dist=0 

    //prints rightward from 5, 1 by 6
    plotLine (5, 1, 0, 6, '6', 1);
    //prints downward from 5,1 by 6, first char shouldn't print 
    plotLine (5, 1, 1, 7, '7', 0);

    //prints leftward from 13, 17 by 5 
    plotLine (13, 17, 0, -7, '@', 0);
    //prints upward from 15, 20 by 11; a char should overlap 
    plotLine (14, 17, 1, -11, '#', 1); 