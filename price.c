/*
 * Program: price.c
 * Purpose: This program takes a list of products and determines, on the basis
 *      of cost/square inch, which is the “best buy”. It also displays a
 *  sorted list of the products in the increasing of their cost/square inch.
 * Author: Mehmet Turhan
 * Date:   11/05/2021
 */

#include <stdio.h>
#define N 100

/*
 * Structure method for the items and important information about them.
 */
struct item {
  int brandCode;
  int productCode;
  int storeCode;
  int sheets;
  float length;
  float width;
  float price;
  float cost;
} ;

/*
 * Defining functions
 */
int getinput(struct item *ip);
void computecost(struct item *ip, int n);
void sortitems(struct item *ip, int n);
void displayitems(struct item *ip, int n);

void main() {
  struct item info[N];
  int n;
  n = getinput(info);
  computecost(info, n);
  sortitems(info, n);
  displayitems(info, n);
}

/*
 * Function: getinput
 * Purpose:  gets the input from the input file.
 *
 * Parameters:
 *    ip: item structure
 *
 * Returns:
 *    loopRep: number of times that the loop repeats.
 *
 */
int getinput(struct item *ip) {

  int loopRep;
  int i=0;
  scanf("%d", &loopRep);

  while (i<loopRep) {
    scanf("%d %d %f %f %d %d %f",&ip->brandCode,&ip->productCode,&ip->length,&ip->width,&ip->sheets,&ip->storeCode,&ip->price);
    ip++; //increment ip
    i++;  //increment i
  }
  return loopRep;
}

/*
 * Function: computecost
 * Purpose:  Calculates the cost of each item.
 *
 * Parameters:
 *    ip: item structure
 *    n: the amount of the items that we want to loop through
 *
 * Returns: NA
 *
 */
void computecost(struct item *ip, int n) {
  int i=0;
  float cost;
  float sqIn;
  while (i < n) {
    sqIn=(ip->length*ip->width*ip->sheets);
    cost = ip->price / sqIn;
    ip->cost = cost; // update cost
    ip++; //increment ip
    i++;  //increment ip
  }
}

/*
 * Function: sortitems
 * Purpose:  Bubble sorts the items' costs
 *
 * Parameters:
 *    ip: item structure
 *    n: the amount of the items that we want to loop through
 *
 * Returns: NA
 *
 */
void sortitems(struct item *ip, int n) {
  int i=0;
  int j=0;
  for (i = 0; i < n; i++) {
    while (j < n - i) {
      if (((ip + j)->cost) < (ip->cost)) { //bubble sort algorithm
        struct item temp = *ip;
        *ip = *(ip+j); // update ip
        *(ip+j) = temp; // update ip+j
      }
      j++; //increment of i
    }
  }
}

/*
 * Function: displayitems
 * Purpose:  Print function to print as the output shown.
 *
 * Parameters:
 *    ip: item structure
 *    n: the amount of the items that we want to loop through
 *
 * Returns: NA
 *
 */
void displayitems(struct item *ip, int n) {
  int i=0;
  char *marketName[] = {"", "Shaw's", "Walmart", "BJ's", "Mom's"};
  char *productBrand[] = {"", "Kleenex", "Charmin", "Delsey", "Generic"};
  char *paperStyle[] = {"", "Tissue", "TP"};

  while (i<n) {
    printf("%s %s at %s: $%0.5f\n",productBrand[ip->brandCode],paperStyle[ip->productCode], marketName[ip->storeCode], ip->cost);
    ip++; //increment ip
    i++;  //increment ip
  }
}
