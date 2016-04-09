float unitconversion(int conversion_type, float input_value) {

  /* character strings for output */

  char* units []={" cm "," inches "," meters "," feet "," km "," miles "," kg "," lb "," litres "," gallons "," celsius "," fahrenheit "," celsius "," kelvin "};

  float converted_output;

  /* array containing slopes and intercepts of all convertibles */

  /* constants initialization : multiplicative constant, its inverse, intercept */
  /* Note intercepts are zero for meters to kilometers conversion etc */
  /* array elements row 0: cm to inches (and inverse) */


  float array_of_constants[7][2]={{1./2.54,0.},{3.2808,0.0},{0.62137,0.0},{2.204,0.0},{0.26417,0.0},{9./5.,32.},{1.,273}};

  /* code 1: cm to inches 2: inches->cm, 3: m->ft, 4: ft->m, 5: km->mi,6: mi-km */
  /* code 7: kg-> lbs, 8:lbs->kg, 9: ltr->galn, 10:galn->ltr, 11:c->f,12:f->c */
  /* code 13:c->K, 14: K->c */

  if(conversion_type<1 ||conversion_type>14) {
    printf("Function unitconversion: type is out of bounds please check options for the conversion you want: Allowed values: 1 to 14 only \n");
    return -999.;
  }


  /* linear relation of the type y=m*x+c assumed for generality even though only relevant for temperature */


/* checking for odd even etc and assigning array values to pick correct slope and intercept */

  int parity,i;
  int to, from;

  parity = conversion_type & 1; /* check to see if the last bit is 1 or 0 assign parity */

  if(parity ==1) {
    i=(conversion_type+1)/2-1;
    converted_output= input_value*array_of_constants[i][0]+array_of_constants[i][1];
    to=conversion_type;
    from=conversion_type-1;
  }
  else {
    i=conversion_type/2-1;
    converted_output= (input_value-array_of_constants[i][1])/(array_of_constants[i][0]);
    to=conversion_type-2;
    from=conversion_type-1;
  }

  printf("You have chosen to convert %f %s to %s \n", input_value, units[from], units[to]);
  printf("%f %s is =%f %s \n", input_value, units[from], converted_output, units[to]);

  return converted_output;


}

