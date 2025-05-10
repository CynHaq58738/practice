/**********************************************************************************************
 * This program creates a Coin class and implements the Collections
 *
 * @name Cynthia Haque
 * @date 9-14-2024
 * @version 2024 
 ********************************************************************************************** */
class Coin implements Collections<Coin>
{
   private String country; // e.g., Canada
   private String denomination; // e.g., 5 cents
   private int year; // e.g., 1970
   private int qualityLevel; // a number between 1 and 70
   private double value; // e.g., $8.33
   private double amountPaid; // e.g., $2.50
   
   public Coin(String country, String denomination, int year, 
                       int qualityLevel, double value, double amountPaid)
   {
      this.country = country;
      this.denomination = denomination;
      this.year = year;
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
   public double getValue()
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
      return denomination + ", " + year + ", from " + country;
   }
   
}