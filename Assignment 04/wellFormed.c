/* =============================================================================
 * Libraries
 * ========================================================================== */
#include "stack.h"
#include <string.h>

/* =============================================================================
 * Main Function
 * ========================================================================== */
int main() {

  char *seq = "[ ( ) ]";

  int i = 0;

  Stack *p = createStack(strlen(seq));

  while (seq[i] != '\0') {
    if ((seq[i] == '(') || (seq[i] == '[')) {
      p = push(p, seq[i]);
    } else if (seq[i] == ')') {
      if (isEmptyStack(p) || getTopElement(p) != '(') {
        printf("Not well-formed\n");
        return 0;
      }
      p = pop(p);
    } else if (seq[i] == ']') {
      if (isEmptyStack(p) || getTopElement(p) != '[') {
        printf("Not well-formed\n");
        return 0;
      }
      p = pop(p);
    }
    i++;
  }
  if (isEmptyStack(p)) {
    printf("Well-formed\n");
  } else {
    printf("Not well-formed\n");
  }
  return 0;
}
