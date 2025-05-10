/**********************************************************************************************
 * This program creates a Sports Card class and implements the Collections
 *
 * @name Cynthia Haque
 * @date 9-14-2024
 * @version 2024 
 ********************************************************************************************** */
class SportCard implements Collections<SportCard>
{
   private String athlete;
   private String sport;
   private String team;
   private int qualityLevel; //a number between 1 and 10
   private double value;
   private double amountPaid;

   public SportCard(String athlete, String sport, String team,
                        int qualityLevel, double value, double amountPaid)
   {
      this.athlete = athlete;
      this.sport = sport;
      this.team = team;
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
      return "Card of " + athlete + ", from team " + team + "(" + sport + ")";
   }

}