public class kt17_1 {
    private static int binary_search(int[] lst, int target){
        int i = 0;
        int j = lst.length - 1;
        while(i < j){
            int m = (i + j) / 2;
            if(lst[m] < target)
                i = m + 1;
            else
                j = m;
        }
        if(lst[i] == target)
            return i;
        else
            return -1;
    }
    public static void main(String[] args){
        int list[] = {1, 3, 5, 7, 9, 11, 13, 14, 17, 20};
        int target = 17;
        System.out.println(binary_search(list, target));
    }
}
