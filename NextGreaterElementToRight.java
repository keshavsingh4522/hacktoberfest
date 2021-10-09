import java.io.*;
import java.util.*;

public class Main {
  public static void display(int[] a) {
    StringBuilder sb = new StringBuilder();

    for (int val : a) {
      sb.append(val + "\n");
    }
    System.out.println(sb);
  }

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int n = Integer.parseInt(br.readLine());
    int[] a = new int[n];
    for (int i = 0; i < n; i++) {
      a[i] = Integer.parseInt(br.readLine());
    }

    int[] nge = solve(a);
    display(nge);
  }

  public static int[] solve(int[] arr) {
    int[] nge = new int[arr.length];

    Stack<Integer> st = new Stack<>();

    nge[arr.length - 1] = -1;
    st.push(arr[arr.length - 1]);
    for(int i = arr.length - 2; i >= 0; i--){
      while(st.size() > 0 && arr[i] >= st.peek()){
        st.pop();
      }     
      if(st.size() > 0){
        nge[i] = st.peek();
      } else {
        nge[i] = -1;
      }
      
      st.push(arr[i]);
    }

    return nge;
  }

}
