public class RemoveDuplicate {
    public static void main(String[] args) {
        String remove = "I love India";
        String newString="";
        for (int i = 0; i < remove.length(); i++) {
            String word=String.valueOf(remove.charAt(i));
            if(!newString.toLowerCase().contains(word.toLowerCase())||word.equals(" ")){
                newString+=word;
            }
        }
        System.out.println(newString);
    }
}
