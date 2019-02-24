import java.util.ArrayList;
import java.util.Random;

public class kt17_2 {
    private static ArrayList<Integer> merge(ArrayList<Integer> left, ArrayList<Integer> right){
        ArrayList<Integer> result = new ArrayList<>();
        int i = 0, j = 0;
        left.add(1000);
        right.add(1000);
        for(int k = 0; k < left.size() + right.size() - 2; ++k){
            if (left.get(i) <= right.get(j)){
                result.add(left.get(i));
                ++i;
            }
            else{
                result.add(right.get(j));
                ++j;
            }
        }
        return result;
    }
    private static ArrayList<Integer> mergeSort(ArrayList<Integer> list){
        if(list.size() < 2)
            return list;
        else {
            int m = list.size() / 2;
            ArrayList<Integer> left = new ArrayList<>();
            for (int i = 0; i < m; i++)
                left.add(list.get(i));
            ArrayList<Integer> right = new ArrayList<>();
            for (int i = m; i < list.size(); i++)
                right.add(list.get(i));
            ArrayList<Integer> L = new ArrayList<>();
            L = merge(mergeSort(left), mergeSort(right));
            return L;
        }
    }
    public static void main(String[] args) {
        ArrayList<Integer> ent = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            Random rd = new Random();
            ent.add(rd.nextInt(100));
        }
        ArrayList<Integer> L;
        L = mergeSort(ent);
        System.out.println(L);

    }
}
