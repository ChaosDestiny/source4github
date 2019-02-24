public class kt10_2 {
    private static int g(int x){
        x = x + 1;
        System.out.println("In g(x): x = " + x);
        h(x);
        int x1 = x;
        return x1;
    }
    private static void h(int x){
        x = x + 1;
        System.out.println("In h(x): x = " + x);
    }
    public static void main(String[] args) {
        int x = 3;
        int z = g(x);
        System.out.println("In main program scope: x = " + x);
        System.out.println("In main program scope: z = " + z);
    }
}
