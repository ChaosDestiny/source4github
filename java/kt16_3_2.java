public class kt16_3_2 {
    public static void main(String[] args){
        for(int num = 10; num <= 20; num ++)
            for(int i = 2; i <= num; i++){
                int j;
                if((num % i) == 0){
                    j = num / i;
                    System.out.println(num + " bang " + i + "*" + j);
                    break;
                }
                else{
                    System.out.println(num + " la so nguyen to");
                    break;
                }
            }
    }
}
