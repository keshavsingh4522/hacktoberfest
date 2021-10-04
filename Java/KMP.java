

public class KMP {

    public void computeLPS( String m,int lps[]){

        int n = m.length();
        int len = 0;
        int i=1;
        lps[0] = 0;

        while(i<n){

            if(m.charAt(i)==m.charAt(len)){


                lps[i] = len+1;
                len++;
                i++;
            }else{

                if(len!=0){
                    len = lps[len-1];
                }else{
                    lps[i]=0;
                    i++;
                }

            }


        }


    }

    public void kmpSearch(String pat,String text){

        int n = pat.length();
        int m = text.length();
        int [] lps = new int[m];
        computeLPS(text,lps);
        int i =0;
        int j=0;
        while(i<n){

            if(pat.charAt(i)
                    ==text.charAt(j)){
                i++;
                j++;
            }
            else{
                if(j!=0){
                    j = lps[j-1];
                }
                else {
                    i++;
                }
            }


            if(j==m){
                System.out.println("Found at index"+(i-m));
                j = lps[j-1];
            }

        }


    }


    public static void main(String[] args) {

        KMP kmp = new KMP();

        String pat ="onionionspi";
        String text = "onions";

        kmp.kmpSearch(pat,text);



    }


}
