public class kt16_2 {
    public static void main(String[] args){
        int i = 2;
        while (i < 100){
            int j = 2;
            while (j <= (i/j)){
                if (0 == (i % j)) break;
                j = j + 1;
                if(j > (i/j))
                    System.out.println(i + " la so nguyen to");
            }
            i = i + 1;
        }
        System.out.println("Good bye!");
    }
}
