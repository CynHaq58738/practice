/****************************************************************************************
 * This program creates an interface using generics
 *
 * @name Cynthia Haque
 * @date 9-14-2024
 * @version 2024 
 **************************************************************************************** */
public interface Collections<T>
{
   public int getQualityLevel();
   public double getValue();
   public void setValue(double value);
   public double calcProfit();
}
