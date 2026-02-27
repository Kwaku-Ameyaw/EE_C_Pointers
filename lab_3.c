# include <stdio.h>
float service_charge=5.0;
void update_dashboard(float current_bill);
float calculate_bill(float unit_purchased);
int main(){
    int start =1;
    while(start){
        float total_charge=0;
        float unit_purchased=0;
        int id_num=0;
        
        printf("Enter meter id: ");
        scanf("%d",&id_num);
        printf("Enter amount of unit to buy: ");
        scanf("%f",&unit_purchased);
        if (unit_purchased>0){
            total_charge=calculate_bill(unit_purchased);
            printf("The cost of %g unit is %g\n",unit_purchased,total_charge);

            update_dashboard(total_charge);
        }
        else{
            printf("Enter a valid unit");
        }

        printf("Do you want to perform another operation? yes=1, no=0");
        scanf("%d",&start);
        switch (start){
            case 1:
            continue;
            default:
            start-=1;
            printf("Thank you for using our services");
        }
    }
    return 0;
}
float calculate_bill(float unit_purchased){
        float total_charge=0;
        if(unit_purchased<= 50){
            total_charge=unit_purchased*0.5 + service_charge;
        }
        else if(unit_purchased <=150){
            total_charge=unit_purchased*0.75+service_charge;
        }
        else {
        total_charge=unit_purchased*1.2+service_charge;
        }      
        return total_charge;

}
void update_dashboard(float current_bill){
    static int customer_count=1;
    static float total_transaction=0;
    customer_count++;
    total_transaction+=current_bill;
    printf("Total customers: %d\n"
        "total transactions: %g\n",customer_count,total_transaction);
}