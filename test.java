import java.util.Scanner;

/**
 * test
 */
public class test {

    public static void main(String[] args) {
        shaizi();
        /*
         * 水仙花数
         */
        System.out.println("水仙花数：");
        int i=100; 
        while( i < 1000){
            if(isArmstrongNumber(i))System.out.println(i);
            i++;
        }
    }
     public static void shaizi(){
        int a = (int)(Math.random()*6+1);
        int b= (int)(Math.random()*6+1);
        int c= (int)(Math.random()*6+1);
        System.out.println("请输入大小还是豹子?");
        Scanner scan = new Scanner(System.in);
        String guess = scan.next();
        int num = a +b +c;
        System.out.println("a="+a+"b="+b+"c="+c);
        if(a==b&&b==c){
            if(guess.equals("豹子")){
                System.out.println("正确");
            }else{
                System.out.println("错");
            }
        }
        else if(num<=9){
            if(guess.equals("小")){
                System.out.println("正确");
            }
            else{
                System.out.println("错");
            }
        }
        else if(num>9){
            if(guess.equals("大")){
                System.out.println("正确");
            }
            else{
                System.out.println("错");
            }
        }
        scan.close();
     }
    /**
     * 水仙花数方法
     */
    public static boolean isArmstrongNumber(int number) {
        int originalNumber = number;
        int sum = 0;
        int digits = String.valueOf(number).length();

        while (number > 0) {
            int digit = number % 10;
            sum += Math.pow(digit, digits);
            number /= 10;
        }
        return sum == originalNumber;
    }
}