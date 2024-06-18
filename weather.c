#include <stdio.h>
#include <string.h>

int main () {
	char filename[] = "san_jose_temperature_2020.txt";
	FILE *file = fopen(filename, "r");
	if (file == NULL) {
		printf("Error opening file.");
		return 1;
	}
	int year, month, day;
	float temperature;
	float total_temperature[12]={0};
	int count[12]= {0};
	
	double max_temp, min_temp;
	char month_name[20];
	
	printf("Date\t\tTemperature (C)\n");
	while (fscanf(file, "%d %d %d %f %f ", &year, &month, &day, &temperature)!=EOF) {
		printf("%d-%02d-%02d\t%.2f\n", year, month, day,temperature);
		total_temperature[month-1] += temperature;
		count[month-1]++;
		if (temperature > max_temp) {
			max_temp = temperature;
		}
		if (temperature <min_temp) {
			min_temp = temperature;
		}
	}
	for (int i = 0; i< 12; i++) {
		if (count[i] >0) {
			double	avg_temperature = total_temperature[i] / count[i]; 
			switch (i+1){
            case 1: strcpy(month_name, "January"); break;
            case 2: strcpy(month_name, "February"); break;
            case 3: strcpy(month_name, "March"); break;
            case 4: strcpy(month_name, "April"); break;
            case 5: strcpy(month_name, "May"); break;
            case 6: strcpy(month_name, "June"); break;
            case 7: strcpy(month_name, "July"); break;
            case 8: strcpy(month_name, "August"); break;
            case 9: strcpy(month_name, "September"); break;
            case 10: strcpy(month_name, "October"); break;
            case 11: strcpy(month_name, "November"); break;
            case 12: strcpy(month_name, "December"); break;
            default: strcpy(month_name, "Unknown"); break;
        }
	printf("%-12s%6.2f  %6.2d\n", month_name, avg_temperature,count[i]);
	}
		 else {
			printf("No data for month %d\n", i + 1);
		}
	}
	printf("Maximum temperature: %.2f\n", max_temp);
	printf("Minimum temperature: %.2f\n", min_temp);
		
	fclose(file);
	return 0;
}

