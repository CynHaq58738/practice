/**********************************************************************************************
 * This program creates a Stamp class and implements the Collections
 *
 * @name Cynthia Haque
 * @date 9-14-2024
 * @version 2024 
 ********************************************************************************************** */
class Stamp implements Collections<Stamp>
{
   private String country; // e.g., Canada
   private String denomination; // e.g., 75 cents
   private int qualityLevel; // a number between 1 and 100
   private double value; // e.g., $1.50
   private double amountPaid; // e.g., $1.00
   
   public Stamp(String country, String denomination, int qualityLevel, double value, double amountPaid)
   {
      this.country = country;
      this.denomination = denomination;
      this.qualityLevel = qualityLevel;
      this.value = value;
      this.amountPaid = amountPaid;   
   }
   
   @Override
   public int getQualityLevel()
   {
      return qualityLevel;
   }
   
   @Override
   public double  getValue()
   {
      return value;
   }
   
   @Override
   public void setValue(double value)
   {
      this.value = value;
   }
   
   @Override
   public double calcProfit()
   {
      return value - amountPaid;
   }
   
   @Override
   public String toString()
   {
      return denomination + ", from " + country;
   }
   
}