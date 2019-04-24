class Student{
    public:
        void makeMove(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor){
            // Your Code
            int i,j;
            int firstI,firstJ,maxI,maxJ;
            int M = 0,A = 3;
            bool findFirst = false,findFirstSolo = false,findBigger = false,findAlone = false,findFirstAlone = false;
            int num = 0;
            int type = 4;
            int diff = 3;
            Color cptColor;

            if(inputColor==Blue){
                cptColor = Red;
            }else{
                cptColor = Blue;
            }

            for(i=0; i<5; i++){
                for(j=0; j<6; j++){
                    if(color[i][j] == inputColor){
                        num++;
                        /*if(Record[i][j] > M){
                            maxI = i;
                            maxJ = j;
                            M = Record[i][j];
                            findMax = true;
                            if(i>0 && i<4 && j>0 && j<5){
                                if( ( ( (Max[i-1][j]-Record[i-1][j]) >= (Max[i][j]-Record[i][j]) ) || color[i-1][j]==Black) 
                                && ( ( (Max[i+1][j]-Record[i+1][j]) >= (Max[i][j]-Record[i][j]) ) || color[i+1][j]==Black)
                                && ( ( (Max[i][j-1]-Record[i][j-1]) >= (Max[i][j]-Record[i][j]) ) || color[i][j-1]==Black)
                                && ( ( (Max[i][j+1]-Record[i][j+1]) >= (Max[i][j]-Record[i][j]) ) || color[i][j+1]==Black)
                                && (color[i-1][j]==cptColor || color[i+1][j]==cptColor || color[i][j-1]==cptColor || color[i][j+1]==cptColor)){
                                    findBigger = true;
                                }
                            }else if(i==0 && j==0){
                                if( ( ( (Max[i+1][j]-Record[i+1][j]) >= (Max[i][j]-Record[i][j]) ) || color[i+1][j]==Black)
                                && ( ( (Max[i][j+1]-Record[i][j+1]) >= (Max[i][j]-Record[i][j]) ) || color[i][j+1]==Black)
                                && (color[i+1][j]==cptColor || color[i][j+1]==cptColor)){
                                    findBigger = true;
                                }
                            }else if(i==4 && j==0){
                                if( ( ( (Max[i-1][j]-Record[i-1][j]) >= (Max[i][j]-Record[i][j]) ) || color[i-1][j]==Black) 
                                && ( ( (Max[i][j+1]-Record[i][j+1]) >= (Max[i][j]-Record[i][j]) ) || color[i][j+1]==Black)
                                && (color[i-1][j]==cptColor || color[i][j+1]==cptColor)){
                                    findBigger = true;
                                }
                            }else if(i==0 && j==5){
                                if( ( ( (Max[i+1][j]-Record[i+1][j]) >= (Max[i][j]-Record[i][j]) ) || color[i+1][j]==Black)
                                && ( ( (Max[i][j-1]-Record[i][j-1]) >= (Max[i][j]-Record[i][j]) ) || color[i][j-1]==Black)
                                && (color[i+1][j]==cptColor || color[i][j-1]==cptColor)){
                                    findBigger = true;
                                }
                            }else if(i==4 && j==5){
                                if( ( ( (Max[i-1][j]-Record[i-1][j]) >= (Max[i][j]-Record[i][j]) ) || color[i-1][j]==Black) 
                                && ( ( (Max[i][j-1]-Record[i][j-1]) >= (Max[i][j]-Record[i][j]) ) || color[i][j-1]==Black)
                                && (color[i-1][j]==cptColor || color[i][j-1]==cptColor)){
                                    findBigger = true;
                                }
                            }else if(i==0){
                                if( ( ( (Max[i+1][j]-Record[i+1][j]) >= (Max[i][j]-Record[i][j]) ) || color[i+1][j]==Black)
                                && ( ( (Max[i][j-1]-Record[i][j-1]) >= (Max[i][j]-Record[i][j]) ) || color[i][j-1]==Black)
                                && ( ( (Max[i][j+1]-Record[i][j+1]) >= (Max[i][j]-Record[i][j]) ) || color[i][j+1]==Black)
                                && (color[i+1][j]==cptColor || color[i][j-1]==cptColor || color[i][j+1]==cptColor)){
                                    findBigger = true;
                                }
                            }else if(j==0){
                                if( ( ( (Max[i-1][j]-Record[i-1][j]) >= (Max[i][j]-Record[i][j]) ) || color[i-1][j]==Black) 
                                && ( ( (Max[i+1][j]-Record[i+1][j]) >= (Max[i][j]-Record[i][j]) ) || color[i+1][j]==Black)
                                && ( ( (Max[i][j+1]-Record[i][j+1]) >= (Max[i][j]-Record[i][j]) ) || color[i][j+1]==Black)
                                && (color[i-1][j]==cptColor || color[i+1][j]==cptColor || color[i][j+1]==cptColor)){
                                    findBigger = true;
                                }
                            }else if(i==4){
                                if( ( ( (Max[i-1][j]-Record[i-1][j]) >= (Max[i][j]-Record[i][j]) ) || color[i-1][j]==Black) 
                                && ( ( (Max[i][j-1]-Record[i][j-1]) >= (Max[i][j]-Record[i][j]) ) || color[i][j-1]==Black)
                                && ( ( (Max[i][j+1]-Record[i][j+1]) >= (Max[i][j]-Record[i][j]) ) || color[i][j+1]==Black)
                                && (color[i-1][j]==cptColor || color[i][j-1]==cptColor || color[i][j+1]==cptColor)){
                                    findBigger = true;
                                }
                            }else if(j==5){
                                if( ( ( (Max[i-1][j]-Record[i-1][j]) >= (Max[i][j]-Record[i][j]) ) || color[i-1][j]==Black) 
                                && ( ( (Max[i+1][j]-Record[i+1][j]) >= (Max[i][j]-Record[i][j]) ) || color[i+1][j]==Black)
                                && ( ( (Max[i][j-1]-Record[i][j-1]) >= (Max[i][j]-Record[i][j]) ) || color[i][j-1]==Black)
                                && (color[i-1][j]==cptColor || color[i+1][j]==cptColor || color[i][j-1]==cptColor )){
                                    findBigger = true;
                                }
                            }
                        }else */if(1 /*Record[i][j] == M*/){
                            if(i>0 && i<4 && j>0 && j<5){
                                if( ( ( (Max[i-1][j]-Record[i-1][j]) >= (Max[i][j]-Record[i][j]) ) || color[i-1][j]==Black || color[i-1][j]==inputColor) 
                                &&  ( ( (Max[i+1][j]-Record[i+1][j]) >= (Max[i][j]-Record[i][j]) ) || color[i+1][j]==Black || color[i+1][j]==inputColor)
                                &&  ( ( (Max[i][j-1]-Record[i][j-1]) >= (Max[i][j]-Record[i][j]) ) || color[i][j-1]==Black || color[i][j-1]==inputColor)
                                &&  ( ( (Max[i][j+1]-Record[i][j+1]) >= (Max[i][j]-Record[i][j]) ) || color[i][j+1]==Black || color[i][j+1]==inputColor)
                                && (color[i-1][j]==cptColor || color[i+1][j]==cptColor || color[i][j-1]==cptColor || color[i][j+1]==cptColor)){
                                    if(Record[i][j]==(Max[i][j]-1)){
                                        maxI = i;
                                        maxJ = j;
                                        M = Record[i][j];
                                        findBigger = true;
                                    }else{
                                    if(color[i-1][j]==cptColor && ( ( (Max[i-1][j]-Record[i-1][j])-(Max[i][j]-Record[i][j]) ) <= diff ) ){
                                        maxI = i;
                                        maxJ = j;
                                        M = Record[i][j];
                                        findBigger = true;
                                        diff = ( (Max[i-1][j]-Record[i-1][j])-(Max[i][j]-Record[i][j]) );
                                    }
                                    if(color[i+1][j]==cptColor && ( ( (Max[i+1][j]-Record[i+1][j])-(Max[i][j]-Record[i][j]) ) <= diff ) ){
                                        maxI = i;
                                        maxJ = j;
                                        M = Record[i][j];
                                        findBigger = true;
                                        diff = ( (Max[i+1][j]-Record[i+1][j])-(Max[i][j]-Record[i][j]) );
                                    }
                                    if(color[i][j-1]==cptColor && ( ( (Max[i][j-1]-Record[i][j-1])-(Max[i][j]-Record[i][j]) ) <= diff ) ){
                                        maxI = i;
                                        maxJ = j;
                                        M = Record[i][j];
                                        findBigger = true;
                                        diff = ( (Max[i][j-1]-Record[i][j-1])-(Max[i][j]-Record[i][j]) );
                                    }
                                    if(color[i][j+1]==cptColor && ( ( (Max[i][j+1]-Record[i][j+1])-(Max[i][j]-Record[i][j]) ) <= diff ) ){
                                        maxI = i;
                                        maxJ = j;
                                        M = Record[i][j];
                                        findBigger = true;
                                        diff = ( (Max[i][j+1]-Record[i][j+1])-(Max[i][j]-Record[i][j]) );
                                    }
                                    }// end of if (going to explode) else 
                                }
                            }else if(i==0 && j==0){
                                if( ( ( (Max[i+1][j]-Record[i+1][j]) >= (Max[i][j]-Record[i][j]) ) || color[i+1][j]==Black || color[i+1][j]==inputColor)
                                && ( ( (Max[i][j+1]-Record[i][j+1]) >= (Max[i][j]-Record[i][j]) ) || color[i][j+1]==Black || color[i][j+1]==inputColor)
                                && (color[i+1][j]==cptColor || color[i][j+1]==cptColor)){
                                    if(Record[i][j]==(Max[i][j]-1)){
                                        maxI = i;
                                        maxJ = j;
                                        M = Record[i][j];
                                        findBigger = true;
                                    }else{
                                    if(color[i+1][j]==cptColor && ( ( (Max[i+1][j]-Record[i+1][j])-(Max[i][j]-Record[i][j]) ) <= diff ) ){
                                        maxI = i;
                                        maxJ = j;
                                        M = Record[i][j];
                                        findBigger = true;
                                        diff = ( (Max[i+1][j]-Record[i+1][j])-(Max[i][j]-Record[i][j]) );
                                    }
                                    if(color[i][j+1]==cptColor && ( ( (Max[i][j+1]-Record[i][j+1])-(Max[i][j]-Record[i][j]) ) <= diff ) ){
                                        maxI = i;
                                        maxJ = j;
                                        M = Record[i][j];
                                        findBigger = true;
                                        diff = ( (Max[i][j+1]-Record[i][j+1])-(Max[i][j]-Record[i][j]) );
                                    }
                                    }// end of if (going to explode) else
                                }
                            }else if(i==4 && j==0){
                                if( ( ( (Max[i-1][j]-Record[i-1][j]) >= (Max[i][j]-Record[i][j]) ) || color[i-1][j]==Black || color[i-1][j]==inputColor) 
                                && ( ( (Max[i][j+1]-Record[i][j+1]) >= (Max[i][j]-Record[i][j]) ) || color[i][j+1]==Black || color[i][j+1]==inputColor)
                                && (color[i-1][j]==cptColor || color[i][j+1]==cptColor)){
                                    if(Record[i][j]==(Max[i][j]-1)){
                                        maxI = i;
                                        maxJ = j;
                                        M = Record[i][j];
                                        findBigger = true;
                                    }else{
                                    if(color[i-1][j]==cptColor && ( ( (Max[i-1][j]-Record[i-1][j])-(Max[i][j]-Record[i][j]) ) <= diff ) ){
                                        maxI = i;
                                        maxJ = j;
                                        M = Record[i][j];
                                        findBigger = true;
                                        diff = ( (Max[i-1][j]-Record[i-1][j])-(Max[i][j]-Record[i][j]) );
                                    }
                                    if(color[i][j+1]==cptColor && ( ( (Max[i][j+1]-Record[i][j+1])-(Max[i][j]-Record[i][j]) ) <= diff ) ){
                                        maxI = i;
                                        maxJ = j;
                                        M = Record[i][j];
                                        findBigger = true;
                                        diff = ( (Max[i][j+1]-Record[i][j+1])-(Max[i][j]-Record[i][j]) );
                                    }
                                    }// end of if (going to explode) else
                                }
                            }else if(i==0 && j==5){
                                if( ( ( (Max[i+1][j]-Record[i+1][j]) >= (Max[i][j]-Record[i][j]) ) || color[i+1][j]==Black || color[i+1][j]==inputColor)
                                && ( ( (Max[i][j-1]-Record[i][j-1]) >= (Max[i][j]-Record[i][j]) ) || color[i][j-1]==Black || color[i][j-1]==inputColor)
                                && (color[i+1][j]==cptColor || color[i][j-1]==cptColor)){
                                    if(Record[i][j]==(Max[i][j]-1)){
                                        maxI = i;
                                        maxJ = j;
                                        M = Record[i][j];
                                        findBigger = true;
                                    }else{
                                    if(color[i+1][j]==cptColor && ( ( (Max[i+1][j]-Record[i+1][j])-(Max[i][j]-Record[i][j]) ) <= diff ) ){
                                        maxI = i;
                                        maxJ = j;
                                        M = Record[i][j];
                                        findBigger = true;
                                        diff = ( (Max[i+1][j]-Record[i+1][j])-(Max[i][j]-Record[i][j]) );
                                    }
                                    if(color[i][j-1]==cptColor && ( ( (Max[i][j-1]-Record[i][j-1])-(Max[i][j]-Record[i][j]) ) <= diff ) ){
                                        maxI = i;
                                        maxJ = j;
                                        M = Record[i][j];
                                        findBigger = true;
                                        diff = ( (Max[i][j-1]-Record[i][j-1])-(Max[i][j]-Record[i][j]) );
                                    }
                                    }// end of if (going to explode) else
                                }
                            }else if(i==4 && j==5){
                                if( ( ( (Max[i-1][j]-Record[i-1][j]) >= (Max[i][j]-Record[i][j]) ) || color[i-1][j]==Black || color[i-1][j]==inputColor) 
                                && ( ( (Max[i][j-1]-Record[i][j-1]) >= (Max[i][j]-Record[i][j]) ) || color[i][j-1]==Black || color[i][j-1]==inputColor)
                                && (color[i-1][j]==cptColor || color[i][j-1]==cptColor)){
                                    if(Record[i][j]==(Max[i][j]-1)){
                                        maxI = i;
                                        maxJ = j;
                                        M = Record[i][j];
                                        findBigger = true;
                                    }else{
                                    if(color[i-1][j]==cptColor && ( ( (Max[i-1][j]-Record[i-1][j])-(Max[i][j]-Record[i][j]) ) <= diff ) ){
                                        maxI = i;
                                        maxJ = j;
                                        M = Record[i][j];
                                        findBigger = true;
                                        diff = ( (Max[i-1][j]-Record[i-1][j])-(Max[i][j]-Record[i][j]) );
                                    }
                                    if(color[i][j-1]==cptColor && ( ( (Max[i][j-1]-Record[i][j-1])-(Max[i][j]-Record[i][j]) ) <= diff ) ){
                                        maxI = i;
                                        maxJ = j;
                                        M = Record[i][j];
                                        findBigger = true;
                                        diff = ( (Max[i][j-1]-Record[i][j-1])-(Max[i][j]-Record[i][j]) );
                                    }
                                    }// end of if (going to explode) else
                                }
                            }else if(i==0){
                                if( ( ( (Max[i+1][j]-Record[i+1][j]) >= (Max[i][j]-Record[i][j]) ) || color[i+1][j]==Black || color[i+1][j]==inputColor)
                                && ( ( (Max[i][j-1]-Record[i][j-1]) >= (Max[i][j]-Record[i][j]) ) || color[i][j-1]==Black || color[i][j-1]==inputColor)
                                && ( ( (Max[i][j+1]-Record[i][j+1]) >= (Max[i][j]-Record[i][j]) ) || color[i][j+1]==Black || color[i][j+1]==inputColor)
                                && (color[i+1][j]==cptColor || color[i][j-1]==cptColor || color[i][j+1]==cptColor)){
                                    if(Record[i][j]==(Max[i][j]-1)){
                                        maxI = i;
                                        maxJ = j;
                                        M = Record[i][j];
                                        findBigger = true;
                                    }else{
                                    if(color[i+1][j]==cptColor && ( ( (Max[i+1][j]-Record[i+1][j])-(Max[i][j]-Record[i][j]) ) <= diff ) ){
                                        maxI = i;
                                        maxJ = j;
                                        M = Record[i][j];
                                        findBigger = true;
                                        diff = ( (Max[i+1][j]-Record[i+1][j])-(Max[i][j]-Record[i][j]) );
                                    }
                                    if(color[i][j-1]==cptColor && ( ( (Max[i][j-1]-Record[i][j-1])-(Max[i][j]-Record[i][j]) ) <= diff ) ){
                                        maxI = i;
                                        maxJ = j;
                                        M = Record[i][j];
                                        findBigger = true;
                                        diff = ( (Max[i][j-1]-Record[i][j-1])-(Max[i][j]-Record[i][j]) );
                                    }
                                    if(color[i][j+1]==cptColor && ( ( (Max[i][j+1]-Record[i][j+1])-(Max[i][j]-Record[i][j]) ) <= diff ) ){
                                        maxI = i;
                                        maxJ = j;
                                        M = Record[i][j];
                                        findBigger = true;
                                        diff = ( (Max[i][j+1]-Record[i][j+1])-(Max[i][j]-Record[i][j]) );
                                    }
                                    }// end of if (going to explode) else
                                }
                            }else if(j==0){
                                if( ( ( (Max[i-1][j]-Record[i-1][j]) >= (Max[i][j]-Record[i][j]) ) || color[i-1][j]==Black || color[i-1][j]==inputColor) 
                                && ( ( (Max[i+1][j]-Record[i+1][j]) >= (Max[i][j]-Record[i][j]) ) || color[i+1][j]==Black || color[i+1][j]==inputColor)
                                && ( ( (Max[i][j+1]-Record[i][j+1]) >= (Max[i][j]-Record[i][j]) ) || color[i][j+1]==Black || color[i][j+1]==inputColor)
                                && (color[i-1][j]==cptColor || color[i+1][j]==cptColor || color[i][j+1]==cptColor)){
                                    if(Record[i][j]==(Max[i][j]-1)){
                                        maxI = i;
                                        maxJ = j;
                                        M = Record[i][j];
                                        findBigger = true;
                                    }else{
                                    if(color[i-1][j]==cptColor && ( ( (Max[i-1][j]-Record[i-1][j])-(Max[i][j]-Record[i][j]) ) <= diff ) ){
                                        maxI = i;
                                        maxJ = j;
                                        M = Record[i][j];
                                        findBigger = true;
                                        diff = ( (Max[i-1][j]-Record[i-1][j])-(Max[i][j]-Record[i][j]) );
                                    }
                                    if(color[i+1][j]==cptColor && ( ( (Max[i+1][j]-Record[i+1][j])-(Max[i][j]-Record[i][j]) ) <= diff ) ){
                                        maxI = i;
                                        maxJ = j;
                                        M = Record[i][j];
                                        findBigger = true;
                                        diff = ( (Max[i+1][j]-Record[i+1][j])-(Max[i][j]-Record[i][j]) );
                                    }
                                    if(color[i][j+1]==cptColor && ( ( (Max[i][j+1]-Record[i][j+1])-(Max[i][j]-Record[i][j]) ) <= diff ) ){
                                        maxI = i;
                                        maxJ = j;
                                        M = Record[i][j];
                                        findBigger = true;
                                        diff = ( (Max[i][j+1]-Record[i][j+1])-(Max[i][j]-Record[i][j]) );
                                    }
                                    }// end of if (going to explode) else
                                }
                            }else if(i==4){
                                if( ( ( (Max[i-1][j]-Record[i-1][j]) >= (Max[i][j]-Record[i][j]) ) || color[i-1][j]==Black || color[i-1][j]==inputColor) 
                                && ( ( (Max[i][j-1]-Record[i][j-1]) >= (Max[i][j]-Record[i][j]) ) || color[i][j-1]==Black || color[i][j-1]==inputColor)
                                && ( ( (Max[i][j+1]-Record[i][j+1]) >= (Max[i][j]-Record[i][j]) ) || color[i][j+1]==Black || color[i][j+1]==inputColor)
                                && (color[i-1][j]==cptColor || color[i][j-1]==cptColor || color[i][j+1]==cptColor)){
                                    if(Record[i][j]==(Max[i][j]-1)){
                                        maxI = i;
                                        maxJ = j;
                                        M = Record[i][j];
                                        findBigger = true;
                                    }else{
                                    if(color[i+1][j]==cptColor && ( ( (Max[i+1][j]-Record[i+1][j])-(Max[i][j]-Record[i][j]) ) <= diff ) ){
                                        maxI = i;
                                        maxJ = j;
                                        M = Record[i][j];
                                        findBigger = true;
                                        diff = ( (Max[i+1][j]-Record[i+1][j])-(Max[i][j]-Record[i][j]) );
                                    }
                                    if(color[i][j-1]==cptColor && ( ( (Max[i][j-1]-Record[i][j-1])-(Max[i][j]-Record[i][j]) ) <= diff ) ){
                                        maxI = i;
                                        maxJ = j;
                                        M = Record[i][j];
                                        findBigger = true;
                                        diff = ( (Max[i][j-1]-Record[i][j-1])-(Max[i][j]-Record[i][j]) );
                                    }
                                    if(color[i][j+1]==cptColor && ( ( (Max[i][j+1]-Record[i][j+1])-(Max[i][j]-Record[i][j]) ) <= diff ) ){
                                        maxI = i;
                                        maxJ = j;
                                        M = Record[i][j];
                                        findBigger = true;
                                        diff = ( (Max[i][j+1]-Record[i][j+1])-(Max[i][j]-Record[i][j]) );
                                    }
                                    }// end of if (going to explode) else
                                }
                            }else if(j==5){
                                if( ( ( (Max[i-1][j]-Record[i-1][j]) >= (Max[i][j]-Record[i][j]) ) || color[i-1][j]==Black || color[i-1][j]==inputColor) 
                                && ( ( (Max[i+1][j]-Record[i+1][j]) >= (Max[i][j]-Record[i][j]) ) || color[i+1][j]==Black || color[i+1][j]==inputColor)
                                && ( ( (Max[i][j-1]-Record[i][j-1]) >= (Max[i][j]-Record[i][j]) ) || color[i][j-1]==Black || color[i][j-1]==inputColor)
                                && (color[i-1][j]==cptColor || color[i+1][j]==cptColor || color[i][j-1]==cptColor )){
                                    if(Record[i][j]==(Max[i][j]-1)){
                                        maxI = i;
                                        maxJ = j;
                                        M = Record[i][j];
                                        findBigger = true;
                                    }else{
                                    if(color[i-1][j]==cptColor && ( ( (Max[i-1][j]-Record[i-1][j])-(Max[i][j]-Record[i][j]) ) <= diff ) ){
                                        maxI = i;
                                        maxJ = j;
                                        M = Record[i][j];
                                        findBigger = true;
                                        diff = ( (Max[i-1][j]-Record[i-1][j])-(Max[i][j]-Record[i][j]) );
                                    }
                                    if(color[i+1][j]==cptColor && ( ( (Max[i+1][j]-Record[i+1][j])-(Max[i][j]-Record[i][j]) ) <= diff ) ){
                                        maxI = i;
                                        maxJ = j;
                                        M = Record[i][j];
                                        findBigger = true;
                                        diff = ( (Max[i+1][j]-Record[i+1][j])-(Max[i][j]-Record[i][j]) );
                                    }
                                    if(color[i][j-1]==cptColor && ( ( (Max[i][j-1]-Record[i][j-1])-(Max[i][j]-Record[i][j]) ) <= diff ) ){
                                        maxI = i;
                                        maxJ = j;
                                        M = Record[i][j];
                                        findBigger = true;
                                        diff = ( (Max[i][j-1]-Record[i][j-1])-(Max[i][j]-Record[i][j]) );
                                    }
                                    }// end of if (going to explode) else
                                }
                            }
                            if(!findBigger){
                                if(i>0 && i<4 && j>0 && j<5){
                                    if( color[i-1][j]!=cptColor && color[i+1][j]!=cptColor && color[i][j-1]!=cptColor && color[i][j+1]!=cptColor
                                     && Record[i][j] <= A){
                                        maxI = i;
                                        maxJ = j;
                                        A = Record[i][j];
                                        findBigger = false;
                                        findAlone = true;
                                    }
                                }else if(i==0 && j==0){
                                    if( (color[i+1][j]!=cptColor && color[i][j+1]!=cptColor)
                                     && Record[i][j] <= A){
                                        maxI = i;
                                        maxJ = j;
                                        A = Record[i][j];
                                        findBigger = false;
                                        findAlone = true;
                                    }
                                }else if(i==4 && j==0){
                                    if( (color[i-1][j]!=cptColor && color[i][j+1]!=cptColor)
                                     && Record[i][j] <= A){
                                        maxI = i;
                                        maxJ = j;
                                        A = Record[i][j];
                                        findBigger = false;
                                        findAlone = true;
                                    }
                                }else if(i==0 && j==5){
                                    if( (color[i+1][j]!=cptColor && color[i][j-1]!=cptColor)
                                     && Record[i][j] <= A){
                                        maxI = i;
                                        maxJ = j;
                                        A = Record[i][j];
                                        findBigger = false;
                                        findAlone = true;
                                    }
                                }else if(i==4 && j==5){
                                    if( (color[i-1][j]!=cptColor && color[i][j-1]!=cptColor)
                                     && Record[i][j] <= A){
                                        maxI = i;
                                        maxJ = j;
                                        A = Record[i][j];
                                        findBigger = false;
                                        findAlone = true;
                                    }
                                }else if(i==0){
                                    if( (color[i+1][j]!=cptColor && color[i][j-1]!=cptColor && color[i][j+1]!=cptColor)
                                     && Record[i][j] <= A){
                                        maxI = i;
                                        maxJ = j;
                                        A = Record[i][j];
                                        findBigger = false;
                                        findAlone = true;
                                    }
                                }else if(j==0){
                                    if( (color[i-1][j]!=cptColor && color[i+1][j]!=cptColor && color[i][j+1]!=cptColor)
                                     && Record[i][j] <= A){
                                        maxI = i;
                                        maxJ = j;
                                        A = Record[i][j];
                                        findBigger = false;
                                        findAlone = true;
                                    }
                                }else if(i==4){
                                    if( (color[i-1][j]!=cptColor && color[i][j-1]!=cptColor && color[i][j+1]!=cptColor)
                                     && Record[i][j] <= A){
                                        maxI = i;
                                        maxJ = j;
                                        A = Record[i][j];
                                        findBigger = false;
                                        findAlone = true;
                                    }
                                }else if(j==5){
                                    if( (color[i-1][j]!=cptColor && color[i+1][j]!=cptColor && color[i][j-1]!=cptColor )
                                     && Record[i][j] <= A){
                                        maxI = i;
                                        maxJ = j;
                                        A = Record[i][j];
                                        findBigger = false;
                                        findAlone = true;
                                    }
                                }
                            }
                            if(!findAlone && !findBigger){
                                maxI = i;
                                maxJ = j;
                                M = Record[i][j];
                                findBigger = false;
                                findAlone = false;
                            }
                            
                        }
                    }
                    if(color[i][j] == White){
                        /*if(!findFirst){
                            firstI = i;
                            firstJ = j;
                            findFirst = true;
                        }else{*/
                            if(i>0 && i<4 && j>0 && j<5){
                                if(color[i-1][j]!=cptColor && color[i+1][j]!=cptColor && color[i][j-1]!=cptColor && color[i][j+1]!=cptColor
                                && color[i-1][j]!=inputColor && color[i+1][j]!=inputColor && color[i][j-1]!=inputColor && color[i][j+1]!=inputColor
                                && Max[i][j] <= type){
                                    firstI = i;
                                    firstJ = j;
                                    findFirstSolo = true;
                                    type = 4;
                                }
                            }else if(i==0 && j==0){
                                if( color[i+1][j]!=cptColor && color[i][j+1]!=cptColor
                                 && color[i+1][j]!=inputColor && color[i][j+1]!=inputColor
                                 && Max[i][j] <= type){
                                    firstI = i;
                                    firstJ = j;
                                    findFirstSolo = true;
                                    type = 2;
                                }
                            }else if(i==4 && j==0){
                                if( color[i-1][j]!=cptColor && color[i][j+1]!=cptColor
                                 && color[i-1][j]!=inputColor && color[i][j+1]!=inputColor
                                 && Max[i][j] <= type){
                                    firstI = i;
                                    firstJ = j;
                                    findFirstSolo = true;
                                    type = 2;
                                }
                            }else if(i==0 && j==5){
                                if( color[i+1][j]!=cptColor && color[i][j-1]!=cptColor
                                 && color[i+1][j]!=inputColor && color[i][j-1]!=inputColor
                                 && Max[i][j] <= type){
                                    firstI = i;
                                    firstJ = j;
                                    findFirstSolo = true;
                                    type = 2;
                                }
                            }else if(i==4 && j==5){
                                if( color[i-1][j]!=cptColor && color[i][j-1]!=cptColor
                                 && color[i-1][j]!=inputColor && color[i][j-1]!=inputColor
                                 && Max[i][j] <= type){
                                    firstI = i;
                                    firstJ = j;
                                    findFirstSolo = true;
                                    type = 2;
                                }
                            }else if(i==0){
                                if( color[i+1][j]!=cptColor && color[i][j-1]!=cptColor && color[i][j+1]!=cptColor
                                 && color[i+1][j]!=inputColor && color[i][j-1]!=inputColor && color[i][j+1]!=inputColor
                                 && Max[i][j] <= type){
                                    firstI = i;
                                    firstJ = j;
                                    findFirstSolo = true;
                                    type = 3;
                                }
                            }else if(j==0){
                                if( color[i-1][j]!=cptColor && color[i+1][j]!=cptColor && color[i][j+1]!=cptColor
                                 && color[i-1][j]!=inputColor && color[i+1][j]!=inputColor && color[i][j+1]!=inputColor
                                 && Max[i][j] <= type){
                                    firstI = i;
                                    firstJ = j;
                                    findFirstSolo = true;
                                    type = 3;
                                }
                            }else if(i==4){
                                if( color[i-1][j]!=cptColor && color[i][j-1]!=cptColor && color[i][j+1]!=cptColor
                                 && color[i-1][j]!=inputColor && color[i][j-1]!=inputColor && color[i][j+1]!=inputColor
                                 && Max[i][j] <= type){
                                    firstI = i;
                                    firstJ = j;
                                    findFirstSolo = true;
                                    type = 3;
                                }
                            }else if(j==5){
                                if( color[i-1][j]!=cptColor && color[i+1][j]!=cptColor && color[i][j-1]!=cptColor
                                 && color[i-1][j]!=inputColor && color[i+1][j]!=inputColor && color[i][j-1]!=inputColor 
                                 && Max[i][j] <= type){
                                    firstI = i;
                                    firstJ = j;
                                    findFirstSolo = true;
                                    type = 3;
                                }
                            }
                        
                        if(!findFirstSolo){
                            if(i>0 && i<4 && j>0 && j<5){
                                if(color[i-1][j]!=cptColor && color[i+1][j]!=cptColor && color[i][j-1]!=cptColor && color[i][j+1]!=cptColor){
                                    firstI = i;
                                    firstJ = j;
                                    findFirstAlone = true;
                                }
                            }else if(i==0 && j==0){
                                if( (color[i+1][j]!=cptColor && color[i][j+1]!=cptColor)){
                                    firstI = i;
                                    firstJ = j;
                                    findFirstAlone = true;
                                }
                            }else if(i==4 && j==0){
                                if( (color[i-1][j]!=cptColor && color[i][j+1]!=cptColor)){
                                    firstI = i;
                                    firstJ = j;
                                    findFirstAlone = true;
                                }
                            }else if(i==0 && j==5){
                                if( (color[i+1][j]!=cptColor && color[i][j-1]!=cptColor)){
                                    firstI = i;
                                    firstJ = j;
                                    findFirstAlone = true;
                                }
                            }else if(i==4 && j==5){
                                if( (color[i-1][j]!=cptColor && color[i][j-1]!=cptColor)){
                                    firstI = i;
                                    firstJ = j;
                                    findFirstAlone = true;
                                }
                            }else if(i==0){
                                if( (color[i+1][j]!=cptColor && color[i][j-1]!=cptColor && color[i][j+1]!=cptColor)){
                                    firstI = i;
                                    firstJ = j;
                                    findFirstAlone = true;
                                }
                            }else if(j==0){
                                if( (color[i-1][j]!=cptColor && color[i+1][j]!=cptColor && color[i][j+1]!=cptColor)){
                                    firstI = i;
                                    firstJ = j;
                                    findFirstAlone = true;
                                }
                            }else if(i==4){
                                if( (color[i-1][j]!=cptColor && color[i][j-1]!=cptColor && color[i][j+1]!=cptColor)){
                                    firstI = i;
                                    firstJ = j;
                                    findFirstAlone = true;
                                }
                            }else if(j==5){
                                if( (color[i-1][j]!=cptColor && color[i+1][j]!=cptColor && color[i][j-1]!=cptColor )){
                                    firstI = i;
                                    firstJ = j;
                                    findFirstAlone = true;
                                }
                            }
                        }
                        if(!findFirstSolo && !findFirstAlone){
                            firstI = i;
                            firstJ = j;
                            findFirst = true;
                        }
                    } // end of white
                } // end of j
            } // end of i
            if(findBigger){
                x = maxI;
                y = maxJ;
            }else if(findFirstSolo){
                x = firstI;
                y = firstJ; 
            }else if(findFirstAlone){
                x = firstI;
                y = firstJ;  
            }else if(findFirst){
                x = firstI;
                y = firstJ;
            }else if(findAlone){
                x = maxI;
                y = maxJ;
            }else{
                x = maxI;
                y = maxJ;
            }
        }
        // Any Code You Want to Add
        int getX(){
            // Your Code
            return x;
        }
        int getY(){
            // Your Code
            return y;
        }
    private:
        int x;
        int y;
    };