
// @filename: main_cunit_template.c 
// @rev: 0.1
// @date: 15-03-2010
// @desc: file modello per un main.c con il framework CUnit

#include <stdlib.h>
#include "CUnit/Basic.h"

/**
 * Aggiungere tutti i metodi di test per le funzioni da testare
 */
void test_xyz (void) { 
 // TODO
}

...

/**
 * Funzioni di inizializzazione e pulizia delle suite.
 * Di default sono funzioni vuote.
 */
int suite_void_init (void) {
    return 0;  
}

int suite_void_cleanup (void) {
    return 0;     
}


int main(int argc, char *argv[]) {   
    CU_ErrorCode error;
	
   /**
    * Definizione dei test array
    * NOTA – L’ORDINE DI INSERIMENTO E’ IMPORTANTE
    * Linea aggiunta
    */ 
    CU_TestInfo test_array_dummy[] = {
      { "test di xyz()", test_xyz },

       ...

      CU_TEST_INFO_NULL,
    };
    
   
     ...

    /**
     * crea le suite e vi aggiunge i test array
     * NOTA – L’ORDINE DI INSERIMENTO E’ IMPORTANTE
     */ 
    CU_SuiteInfo suites[] = {
      { "test suite per ... ", suite_void_init, suite_void_cleanup, test_array_dummy },     

      ...
     
      CU_SUITE_INFO_NULL,
    };   


   /* inizializza registro – e’ la prima istruzione */ 
   if (CUE_SUCCESS != CU_initialize_registry()) {
      error = CU_get_error();
      system("PAUSE");
      return -1;
   }

   // add the suites to the registry 
   error = CU_register_suites(suites);
   
   if (CUE_SUCCESS != error) {
      CU_cleanup_registry();
      error = CU_get_error();
      system("PAUSE");
      return -1;
   }


   /**
    * Esegue tutti i casi di test con output sulla console
    */ 
   CU_basic_set_mode(CU_BRM_VERBOSE); 
   CU_basic_run_tests();
   
   /**
    * Pulisce il registro e termina lo unit test
    */
   CU_cleanup_registry(); 
   error = CU_get_error(); 
   system("PAUSE");	
   return error;
}

