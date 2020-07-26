package Code;

public class LexOrder {
    public String between(String A, String B) {
        String ans = A +'a';
        for(int i = 0; i < ans.length(); i++) {
            if(i >= B.length()) break;
            if(ans.charAt(i) > B.charAt(i)) return "IMPOSSIBLE";
        }
        if(ans.equals(B)) return "IMPOSSIBLE";
        return ans;
    }
}
