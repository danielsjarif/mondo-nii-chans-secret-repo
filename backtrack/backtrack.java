public class BoardingSchool{


    private final int DAYS = 7;
    private final int ROWS = 5;
    private final int COLUMNS = 3;
    private final int GIRLS = 15;
    private SchoolGirl[][][] solution = new SchoolGirl[DAYS][ROWS][COLUMNS];

    public BoardingSchool(){
        firstDay();
        restOfTheWeek();
    }

    private void firstDay(){
        int girl = 0;
        for(int j = 0; j < ROWS; j++){
            for(int k = 0; k < COLUMNS; k++){
                solution[0][j][k] = new SchoolGirl(girl);
                girl++;
            }
        }
    }
    private void restOfTheWeek(){
        for(int i = 1; i < DAYS; i++){
            int girl = 0;
            for(int j = 0; i < ROWS; j++){
                for(int k = 0; k < COLUMNS; k++){

                    solution[i][j][k] = new SchoolGirl(girl);
                    girl++;
                }
            }
        }
    }

    private void letsTryThatAgain(){

    }

    private boolean haveWeMetBefore(int day, int row, int column, SchoolGirl schoolGirl){
        if(column == 1){
            return solution[day][row][column].hasMet(solution[day][row][column - 1]);
        }else if(column == 2){
            return solution[day][row][column].hasMet(solution[day][row][column - 1]) && solution[day][row][column].hasMet(solution[day][row][column - 2]);
        }else{
            return false;
        }
    }


    private class SchoolGirl{

        private final int NUMBER_OF_SCHOOL_GIRLS = 15;
        private int number;
        private boolean[] hasMet = new boolean[NUMBER_OF_SCHOOL_GIRLS];


        public SchoolGirl(int number){
            this.number = number;
            for(int i = 0; i <= NUMBER_OF_SCHOOL_GIRLS - 1; i++){
                this.hasMet[i] = false;
            }
            this.hasMet[number] = true;
        }

        public int getNumber(){
            return this.number;
        }

        public boolean[] getHasMet(){
            return this.hasMet;
        }

        public boolean hasMet(SchoolGirl schoolGirl){
            return this.hasMet[schoolGirl.getNumber()];
        }

        public boolean hasMet(int schoolGirl){
            return this.hasMet[schoolGirl];
        }

        public void meets(SchoolGirl schoolGirl){
            hasMet[schoolGirl.getNumber()] = true;
        }



    }

}
