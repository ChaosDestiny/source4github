public class kt16_3_3 {
    public static void main(String[] args){
        int numPaycodes[] = {1, 2, 3, 4, 5};
        int numDivisions[] = {6, 7, 8, 9, 10};
        int sum = 0;
        for(int i = 0; i < numPaycodes.length; i++)
            sum = sum + numPaycodes[i];
        for(int j = 0; j < numDivisions.length; j++) {
            sum = sum + numDivisions[j];
            for(int i = 0; i < numDivisions.length; i++)
                sum = sum + numDivisions[i];
        }
        System.out.println(sum);
    }
}
