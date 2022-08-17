/* Please feel free to modify any content */

/* Definition section */
%{
    #include "compiler_hw_common.h" //Extern variables that communicate with lex
    // #define YYDEBUG 1
    // int yydebug = 1;
    
    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    int yylex_destroy ();
    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
       
    }

    /* Used to generate code */
    /* As printf; the usage: CODEGEN("%d - %s\n", 100, "Hello world"); */
    /* We do not enforce the use of this macro */
    #define CODEGEN(...) \
        do { \
            for (int i = 0; i < g_indent_cnt; i++) { \
                fprintf(fout, "\t"); \
            } \
            fprintf(fout, __VA_ARGS__); \
        } while (0)

    /* Symbol table function - you can add new functions if needed. */
    
    int if_series_comp_id = 0;
    struct symbol_table symbolTable[M];
    int case_id = 0;
    int case_pre_num = 0;
    int case_arr[N];
    int scopeID = 0; // synbolTable[0] = scopeID 1 
    int first_insert = 1;
    int addr_cnt = -1;
    int inside_each_scope_id[M];
    char *indent = "";
    char error_message[M] = "";
    int num_of_ForClause = 0;
    int forLevel = 0;
    char left[10] = "";
    char right[10] = "";
    int previous_for = 0;
    int forNum = 0;
    
    /* Global variables */
    bool g_has_error = false;
    FILE *fout = NULL; //for write j.file
    int g_indent_cnt = 0;
%}

%error-verbose

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 *  - you can add new fields if needed.
 */
%union {
    int i_val;
    float f_val;
    char *s_val;
    bool b_val;
    char c_val;
    /* ... */
}

/* Token without return */
%token VAR NEWLINE
%token INT FLOAT BOOL STRING CHAR
%token INC DEC GEQ LOR LAND 
%token ADD_ASSIGN SUB_ASSIGN 
%token IF ELSE FOR SWITCH CASE
%token PRINT 
%token TRUE 
%token FALSE 
%token DEFAULT 
%token RETURN 
%token FUNC FUNCOPEN
%token PACKAGE 
%token IDENT
%token EQL 
%token NEQ 
%token LEQ
%token MUL_ASSIGN 
%token QUO_ASSIGN 
%token REM_ASSIGN
%token PRINTLN

/* Token with return, which need to sepcify type */
%token <i_val> INT_LIT
%token <s_val> STRING_LIT
%token <f_val> FLOAT_LIT
%token <b_val> BOOL_LIT
%token <c_val> CHAR_LIT

/* Nonterminal with return, which need to sepcify type */
%type <s_val> Type ReturnType

/* associative */
%left '[' ']'
%left '<' '>' GEQ LEQ EQL NEQ
%left '+' '-' '*' '/' '%'
%right '=' '!' 
%right ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN QUO_ASSIGN REM_ASSIGN 
%right AND OR

/* Yacc will start at this nonterminal */
%start Program

/* Grammar section */
%%

Program
    :  GlobalStatementList 
;

GlobalStatementList 
    :  GlobalStatementList GlobalStatement
    |  GlobalStatement 
;

GlobalStatement
    : PackageStmt NEWLINE  
    | FunctionDeclStmt 
    | NEWLINE 
;

PackageStmt 
    : PACKAGE IDENT {
        printf("package: %s\n", $<s_val>2);
    }
;

FunctionDeclStmt 
    : FUNC IDENT {
        indent = ($<s_val>2);
        printf("func: %s\n", $<s_val>2); 
    } '(' ParameterList ')' ReturnType FuncBlock {
        dump_symbol();
    }
;

ParameterList // 宣告函式時
    : IDENT Type
    | ParameterList ',' IDENT Type 
    |
;

ReturnType
    : INT {
        $<s_val>$ = ("int32");
    }
    | FLOAT {
        $<s_val>$ = ("float32");
    }
    | STRING {
        $<s_val>$ = ("string");
    }
    | BOOL {
        $<s_val>$ = ("bool");
    }
    | CHAR {
        $<c_val>$ = ("char");
    }
    | 
;

FuncBlock
    : '{' {
        create_symbol();
        printf("func_signature: ("")'V'\n");
        insert_symbol(indent, "func");
    } StatementList '}'
;

StatementList 
    :  Statement 
    |  StatementList Statement 
    |
;

Statement
    : DeclarationStmt NEWLINE
    | SimpleStmt NEWLINE
    | Block
    | IfStmt
    | ForStmt
    | SwitchStmt
    | CaseStmt
    | PrintStmt NEWLINE
    | ReturnStmt NEWLINE
    | UseFunction
    | NEWLINE
;

DeclarationStmt
    : VAR IDENT Type {
        insert_symbol($<s_val>2, $<s_val>3);
        if(strcmp(getType($<s_val>3), "int32") == 0){
            CODEGEN("ldc 0\nistore %d\n", get_address($<s_val>2));
        }
        else if(strcmp(getType($<s_val>3), "float32") == 0){
            CODEGEN("ldc 0.0\nfstore %d\n", get_address($<s_val>2));
        }
        else if(strcmp(getType($<s_val>3), "string") == 0){
            CODEGEN("ldc \"\"\nastore %d\n", get_address($<s_val>2));
        }
        else if(strcmp(getType($<s_val>3), "bool") == 0){
            CODEGEN("ldc 0\nistore %d\n", get_address($<s_val>2));
        }
        else if(strcmp(getType($<s_val>3), "char") == 0){
            CODEGEN("ldc \'\'\nastore %d\n", get_address($<s_val>2));
        }
    }
    | VAR IDENT Type '=' Expression { // ldc will CODEGEN at expression->...->literal
        insert_symbol($<s_val>2, $<s_val>3); 
        if(strcmp(getType($<s_val>3), "int32") == 0){
            CODEGEN("istore %d\n", get_address($<s_val>2));
        }
        else if(strcmp(getType($<s_val>3), "float32") == 0){
            CODEGEN("fstore %d\n", get_address($<s_val>2));
        }
        else if(strcmp(getType($<s_val>3), "string") == 0){
            CODEGEN("astore %d\n", get_address($<s_val>2));
        }
        else if(strcmp(getType($<s_val>3), "bool") == 0){
            CODEGEN("istore %d\n", get_address($<s_val>2));
        }
        else if(strcmp(getType($<s_val>3), "char") == 0){
            CODEGEN("astore %d\n", get_address($<s_val>2));
        }
    }
;

SimpleStmt 
    : AssignmentStmt
    | Expression
    | IncDecStmt
;

AssignmentStmt
    : Expression assign_op Expression {
        strcpy(left, getType($<s_val>1));
        strcpy(right, getType($<s_val>3));
        if(strcmp($<s_val>2, "ASSIGN") == 0){ // =
            if(strcmp(left, right) != 0){ // error: when assign, type mismatched
                g_has_error = 1;
                printf(error_message, "invalid operation: %s (mismatched types %s and %s)", $<s_val>2, left, right);
                yyerror(error_message);
            }
            else{
                if(strcmp(getType($<s_val>3), "int32") == 0){
                    CODEGEN("istore %d\n", get_address($<s_val>1));
                }
                else if(strcmp(getType($<s_val>3), "float32") == 0){
                    CODEGEN("fstore %d\n", get_address($<s_val>1));
                }
                else if(strcmp(getType($<s_val>3), "string") == 0){
                    CODEGEN("astore %d\n", get_address($<s_val>1));
                }
                else if(strcmp(getType($<s_val>3), "bool") == 0){
                    CODEGEN("istore %d\n", get_address($<s_val>1));
                }
                else if(strcmp(getType($<s_val>3), "char") == 0){
                    CODEGEN("astore %d\n", get_address($<s_val>1));
                }
            }
        }
        else{
            if(strcmp($<s_val>2, "ADD_ASSIGN") == 0){
                if("int32" == getType($<s_val>3)){
                    CODEGEN("iadd\nistore %d\n", get_address($<s_val>1));
                }
                else{
                    CODEGEN("fadd\nfstore %d\n", get_address($<s_val>1));
                }
            }
            else if($<s_val>2 == "SUB_ASSIGN"){
                if(strcmp(getType($<s_val>3), "int32") == 0){
                    CODEGEN("isub\nistore %d\n", get_address($<s_val>1));
                }
                else{
                    CODEGEN("fsub\nfstore %d\n", get_address($<s_val>1));
                }
            }
            else if(strcmp($<s_val>2, "MUL_ASSIGN") == 0){
                if(strcmp(getType($<s_val>3), "int32") == 0){
                    CODEGEN("imul\nistore %d\n", get_address($<s_val>1));
                }
                else if(strcmp(getType($<s_val>3), "float32") == 0){
                    CODEGEN("fmul\nfstore %d\n",get_address($<s_val>1));
                }
            }
            else if(strcmp($<s_val>2, "QUO_ASSIGN") == 0){
                if(strcmp(getType($<s_val>3), "int32") == 0){
                    CODEGEN("idiv\nistore %d\n", get_address($<s_val>1));
                }
                else if(strcmp(getType($<s_val>3), "float32") == 0){
                    CODEGEN("fdiv\nfstore %d\n", get_address($<s_val>1));
                }
            }
            else if(strcmp($<s_val>2, "REM_ASSIGN") == 0){ // only int32
                CODEGEN("irem\nistore %d\n", get_address($<s_val>1));
            }
        }
        printf("%s\n",$<s_val>2);
    }
;

IncDecStmt 
    : Expression INC {
        printf("INC\n");
        if(strcmp(getType($<s_val>1), "int32") == 0){
            CODEGEN("iload %d\nldc 1\niadd\nistore %d\n", get_address($<s_val>1), get_address($<s_val>1));
        }
        else if(strcmp(getType($<s_val>1), "float32") == 0){
            CODEGEN("fload %d\nldc 1.0\nfadd\nfstore %d\n", get_address($<s_val>1), get_address($<s_val>1));
        }
    }
    | Expression DEC {
        printf("DEC\n");
        if(strcmp(getType($<s_val>1), "int32") == 0){
            CODEGEN("iload %d\nldc 1\nisub\nistore %d\n", get_address($<s_val>1), get_address($<s_val>1));
        }
        else if(strcmp(getType($<s_val>1), "float32") == 0){
            CODEGEN("fload %d\nldc 1.0\nfsub\nfstore %d\n", get_address($<s_val>1), get_address($<s_val>1));
        }
    }
;

Type
    : INT {
        $<s_val>$ = ("int32");
        if(scopeID - 1 >= 0){ // record type
            symbolTable[scopeID - 1].type[addr_cnt] = ("int32");
            symbolTable[scopeID - 1].func_sig[addr_cnt] = ("-");
        }
    }
    | FLOAT {
        $<s_val>$ = ("float32");  
        if(scopeID - 1 >= 0){
            symbolTable[scopeID - 1].type[addr_cnt] = "float32";
            symbolTable[scopeID - 1].func_sig[addr_cnt] = "-";
        }
    }
    | STRING {
        $<s_val>$ = ("string");  
        if(scopeID - 1 >= 0){
            symbolTable[scopeID - 1].type[addr_cnt] = ("string");
            symbolTable[scopeID - 1].func_sig[addr_cnt] = ("-");
        }      
    }
    | BOOL {
        $<s_val>$ = ("bool"); 
        if(scopeID - 1 >= 0){
            symbolTable[scopeID - 1].type[addr_cnt] = ("bool");
            symbolTable[scopeID - 1].func_sig[addr_cnt] = ("-");
        }             
    }
    | CHAR {
        $<c_val>$ = ("char"); 
        if(scopeID - 1 >= 0){
            symbolTable[scopeID - 1].type[addr_cnt] = ("char");
            symbolTable[scopeID - 1].func_sig[addr_cnt] = ("-");
        }   
    }
    |
;

UseFunction // use function
    : IDENT '(' TrainsitParaList ')'
;

TrainsitParaList // 使用func時傳入的參數 
    : TrainsitParaList ',' IDENT
    | TrainsitParaList ',' FLOAT_LIT
    | TrainsitParaList ',' CHAR_LIT
    | TrainsitParaList ',' INT_LIT
    | TrainsitParaList ',' BOOL_LIT
    | TrainsitParaList ',' '"' STRING_LIT '"'
    | IDENT
    |
;

CaseStmt
    :  CASE INT_LIT {
        printf("case %d\n", $<i_val>2);
        case_arr[case_id] = $<i_val>2;
        CODEGEN("L_case_%d:\n", case_id);
        case_id++;
    } ':' Block {
        CODEGEN("\tgoto L_switch_end_%d\n", case_pre_num);
    }
    | CASE CHAR_LIT {
        printf("case %c\n", $<c_val>2);
        case_arr[case_id] = $<c_val>2;
        CODEGEN("L_case_%c:\n", case_id);
        case_id++;
    } ':' Block {
        CODEGEN("\tgoto L_switch_end_%d\n", case_pre_num);
    }
    | DEFAULT {
        case_arr[case_id] = -1; // default
        CODEGEN("L_case_%d:\n", case_id);
    } ':' Block {
        CODEGEN("\tgoto L_switch_end_%d\n", case_pre_num);
    }
;

SwitchStmt
    : SWITCH Operand {
        CODEGEN("iload %d\ngoto L_switch_begin_%d\n", get_address($<s_val>2), case_pre_num);
    } Block {
        CODEGEN("L_switch_begin_%d:\nlookupswitch\n", case_pre_num);
        int i = case_pre_num;
        while(i <= case_id){
            if(case_arr[i] == -1){
                CODEGEN("\tdefault: L_case_%d\n", i);
            }
            else{
                CODEGEN("\t%d: L_case_%d\n", case_arr[i], i);
            }
            i++;
        }  
        CODEGEN("L_switch_end_%d:\n", case_pre_num);
        case_pre_num = ++case_id;
    }
;

assign_op 
    : '=' {
        $<s_val>$ = "ASSIGN";
    }
    | ADD_ASSIGN {
        $<s_val>$ = ("ADD_ASSIGN");
    }
    | SUB_ASSIGN {
        $<s_val>$ = ("SUB_ASSIGN");
    }
    | MUL_ASSIGN {
        $<s_val>$ = ("MUL_ASSIGN");
    }
    | QUO_ASSIGN {
        $<s_val>$ = ("QUO_ASSIGN");
    }
    | REM_ASSIGN {
        $<s_val>$ = ("REM_ASSIGN");
    }
;

Expression
    : Expression LOR Expression1 {
        char *leftType = getType($<s_val>1);
        char *rightType = getType($<s_val>3);
        $<s_val>$ = ("bool");
        // type error
        strcpy(left, getType($<s_val>1));
        strcpy(right, getType($<s_val>3));
        if(strcmp(left, "bool") != 0 || strcmp(right, "bool") != 0){
            if(strcmp(left, "bool") != 0){
                printf(error_message, "invalid operation: (operator LOR not defined on %s)", left);
            }
            else if(strcmp(right, "bool") != 0){
                printf(error_message, "invalid operation: (operator LOR not defined on %s)", right);
            }
            yyerror(error_message);
            g_has_error = 1;
        }
        else{
            CODEGEN("ior\n");
        }
        printf("LOR\n"); 
    }
    | Expression1 {
        $<s_val>$ = ($<s_val>1);
    }
;

Expression1
    : Expression1 LAND Expression2 { 
        char *leftType = getType($<s_val>1);
        char *rightType = getType($<s_val>3);
        $<s_val>$ = ("bool"); 
        // type error
        strcpy(left, getType($<s_val>1));
        strcpy(right, getType($<s_val>3));
        if(strcmp(left, "bool") != 0 || strcmp(right, "bool") != 0){
            if(strcmp(left, "bool") != 0){
                printf(error_message, "invalid operation: (operator LAND not defined on %s)", left);
            }
            else if(strcmp(right, "bool") != 0){
                printf(error_message, "invalid operation: (operator LAND not defined on %s)", right);
            }
            yyerror(error_message);
            g_has_error = 1;
        }
        else{
            CODEGEN("iand\n");
        }
        printf("LAND\n"); 
    }
    | Expression2 {
        $<s_val>$ = ($<s_val>1);
    }
;

Expression2
    : Expression2 '<' Expression3 { 
        $<s_val>$ = ("bool"); // return type is bool
        // type error
        strcpy(left, getType($<s_val>1));
        strcpy(right, getType($<s_val>3));
        if(strcmp(left, right) != 0){
            g_has_error = 1;
            printf(error_message, "invalid operation: LSS (mismatched types %s and %s)", left, right);
            yyerror(error_message);
        }
        else{
            if(strcmp(right, "int32") == 0){
                CODEGEN("isub\n");
            }
            else if(strcmp(right, "float32") == 0){
                CODEGEN("fcmpl\n");
            }
            CODEGEN("iflt L_cmp_begin_%d\n\ticonst_0\n\tgoto L_cmp_end_%d\nL_cmp_begin_%d:\n\ticonst_1\nL_cmp_end_%d:\n", if_series_comp_id, if_series_comp_id, if_series_comp_id, if_series_comp_id++);
        }
        printf("LSS\n");
    }
    | Expression2 '>' Expression3 {
        $<s_val>$ = ("bool"); 
        // type error                               
        strcpy(left, getType($<s_val>1));
        strcpy(right, getType($<s_val>3));
        if(strcmp(left, right) != 0){
            g_has_error = 1;
            printf(error_message, "invalid operation: GTR (mismatched types %s and %s)", left, right);
            yyerror(error_message);
        }
        else{
            if(strcmp(right, "int32") == 0){
                CODEGEN("isub\n");
            }
            else if(strcmp(right, "float32") == 0){
                CODEGEN("fcmpl\n");
            }
            CODEGEN("ifgt L_cmp_begin_%d\n\ticonst_0\n\tgoto L_cmp_end_%d\nL_cmp_begin_%d:\n\ticonst_1\nL_cmp_end_%d:\n", if_series_comp_id, if_series_comp_id, if_series_comp_id, if_series_comp_id);
            if_series_comp_id++;
        }
        printf("GTR\n");
    }
    | Expression2 LEQ Expression3 { 
        // type error      
        $<s_val>$ = ("bool");            
        strcpy(left, getType($<s_val>1));
        strcpy(right, getType($<s_val>3));
        if(strcmp(left, right) != 0){ 
            g_has_error = 1;
            printf(error_message, "invalid operation: LEQ (mismatched types %s and %s)", left, right);
            yyerror(error_message);
        }
        else{
            if(strcmp(right, "int32") == 0){
                CODEGEN("isub\n");
            }
            else if(strcmp(right, "float32") == 0){
                CODEGEN("fcmpl\n");
            }
            CODEGEN("ifle L_cmp_begin_%d\n\ticonst_0\n\tgoto L_cmp_end_%d\nL_cmp_begin_%d:\n\ticonst_1\nL_cmp_end_%d:\n", if_series_comp_id, if_series_comp_id, if_series_comp_id, if_series_comp_id);
            if_series_comp_id++;
        }
        printf("LEQ\n"); 
    }
    | Expression2 GEQ Expression3 { 
        // type error
        strcpy(left, getType($<s_val>1));
        strcpy(right, getType($<s_val>3));
        if(strcmp(left, right) != 0){
            g_has_error = 1;
            printf(error_message, "invalid operation: GEQ (mismatched types %s and %s)", left, right);
            yyerror(error_message); 
        }
        else{
            if(strcmp(right, "int32") == 0){
                CODEGEN("isub\n");
            }
            else if(strcmp(right, "float32") == 0){
                CODEGEN("fcmpl\n");
            }
            CODEGEN("ifge L_cmp_begin_%d\n\ticonst_0\n\tgoto L_cmp_end_%d\nL_cmp_begin_%d:\n\ticonst_1\nL_cmp_end_%d:\n", if_series_comp_id, if_series_comp_id, if_series_comp_id, if_series_comp_id);
            if_series_comp_id++;
        }
        $<s_val>$ = ("bool");
        printf("GEQ\n");
    }
    | Expression2 EQL Expression3 {
        // type error
        $<s_val>$ = ("bool");
        strcpy(left, getType($<s_val>1));
        strcpy(right, getType($<s_val>3));
        if(strcmp(left, right) != 0){
            g_has_error = 1;
            printf(error_message, "invalid operation: EQL (mismatched types %s and %s)", left, right);
            yyerror(error_message);  
        }
        else{
            if(strcmp(right, "int32") == 0){
                CODEGEN("isub\n");
            }
            else if(strcmp(right, "float32") == 0){
                CODEGEN("fcmpl\n");
            }
            CODEGEN("ifeq L_cmp_begin_%d\n\ticonst_0\n\tgoto L_cmp_end_%d\nL_cmp_begin_%d:\n\ticonst_1\nL_cmp_end_%d:\n", if_series_comp_id, if_series_comp_id, if_series_comp_id, if_series_comp_id);
            if_series_comp_id++;
        }
        printf("EQL\n");
    }
    | Expression2 NEQ Expression3 { 
        $<s_val>$ = ("bool");
        // type error
        strcpy(left, getType($<s_val>1));
        strcpy(right, getType($<s_val>3));
        if(strcmp(left, right) != 0){
            g_has_error = 1;
            printf(error_message, "invalid operation: NEQ (mismatched types %s and %s)", left, right);
            yyerror(error_message);
        }
        else{
            if(strcmp(right, "int32") == 0){
                CODEGEN("isub\n");
            }
            else if(strcmp(right, "float32") == 0){
                CODEGEN("fcmpl\n");
            }
            CODEGEN("ifne L_cmp_begin_%d\n\ticonst_0\n\tgoto L_cmp_end_%d\nL_cmp_begin_%d:\n\ticonst_1\nL_cmp_end_%d:\n", if_series_comp_id, if_series_comp_id, if_series_comp_id, if_series_comp_id);
            if_series_comp_id++;
        }
        printf("NEQ\n");
    }
    | Expression3 {
        $<s_val>$ = ($<s_val>1);
    }
;

Expression3
    : Expression3 '+' Expression4 {
        // type error
        strcpy(left, getType($<s_val>1));
        strcpy(right, getType($<s_val>3));
        if(strcmp(left, right) != 0){ 
            printf(error_message, "invalid operation: ADD (mismatched types %s and %s)", left,right);
            yyerror(error_message);
            g_has_error = 1;
        }
        else{
            if(strcmp(right, "int32") == 0){
                CODEGEN("iadd\n");
            }
            else if(strcmp(right, "float32") == 0){
                CODEGEN("fadd\n");
            }
        }
        printf("ADD\n");
    }
    | Expression3 '-' Expression4 { 
        // type error
        strcpy(left, getType($<s_val>1));
        strcpy(right, getType($<s_val>3));
        if(strcmp(left, right) != 0){
            printf(error_message, "invalid operation: SUB (mismatched types %s and %s)", left,right);
            yyerror(error_message);
            g_has_error = 1;        
        }
        else{
            if(strcmp(right, "int32") == 0){
                CODEGEN("isub\n");
            }
            else if(strcmp(right, "float32") == 0){                        
                CODEGEN("fsub\n");
            }
        }
        printf("SUB\n"); 
    }
    | Expression4 {
        $<s_val>$ = ($<s_val>1);
    }
;

Expression4
    : Expression4 '*' Expression5 {
        if(strcmp(getType($<s_val>1), "int32") == 0 && strcmp(getType($<s_val>3), "int32") == 0){
            CODEGEN("imul\n");
        }
        else{ // int32/float32 or float32/int32 or float32/float32
            CODEGEN("fmul\n");
        }
        printf("MUL\n");
    }
    | Expression4 '/' Expression5 {
        if(strcmp(getType($<s_val>1), "int32") == 0 && strcmp(getType($<s_val>3), "int32") == 0){
            CODEGEN("idiv\n");
        }
        else{ // int32/float32 or float32/int32 or float32/float32
            CODEGEN("fdiv\n");
        }
        printf("QUO\n"); 
    }
    | Expression4 '%' Expression5 {
        // type error
        strcpy(left, getType($<s_val>1));
        strcpy(right, getType($<s_val>3));                               
        if(strcmp(left, "int32") != 0 || strcmp(right, "int32") != 0){
            g_has_error = 1;
            if(strcmp(left, "int32") != 0){
                printf(error_message, "invalid operation: (operator REM not defined on %s)", left);
                g_has_error = 1;
            }
            else{
                printf(error_message, "invalid operation: (operator REM not defined on %s)", right);
                g_has_error = 1;
            }
            yyerror(error_message);                                
        }
        else{
            CODEGEN("irem\n");
        }
        printf("REM\n"); 
    }
    | Expression5 {
        $<s_val>$ = ($<s_val>1);
    }
;

Expression5 // UnaryExpr
    : PrimaryExpr {
        $<s_val>$ = ($<s_val>1);
    }
    | unary_op Expression5 {
        printf("%s\n", $<s_val>1); 
        $<s_val>$ = (getType($<s_val>2));
        if(strcmp($<s_val>1, "POS") == 0){
            ; // do nothing
        }
        else if(strcmp($<s_val>1, "NEG") == 0){
            if(strcmp(getType($<s_val>2), "int32") == 0){
                CODEGEN("ineg\n");
            }
            else if(strcmp(getType($<s_val>2), "float32") == 0){
                CODEGEN("fneg\n");
            }
        }
        else if(strcmp(getType($<s_val>1), "NOT") == 0){
            CODEGEN("iconst_1\n");
            CODEGEN("ixor\n");
        } 
    }
;

PrimaryExpr
    : Operand { // literal, indent, (expression)
        $<s_val>$ = ($<s_val>1);
    }
    | ConversionExpr {
        $<s_val>$ = (getType($<s_val>1));
    }
    | IndexExpr // true, false
;

Operand
    : Literal {
        $<s_val>$ = ($<s_val>1);
    }
    | IDENT {
        $<s_val>$ = ($<s_val>1); 
        int isdefined = 0;
        int ii = 0;
        while(ii < scopeID){
            int jj = 0;
            while(jj < N){
                if(strcmp(symbolTable[ii].name[jj], $<s_val>1) == 0){
                    isdefined = 1;
                }
                jj++;
            }
            ii++;
        }
        if(isdefined == 0){ // error: undefine
            g_has_error = 1;
            printf("error:%d: undefined: %s\n", yylineno + 1, $<s_val>1);
        }
        lookup_symbol($<s_val>1);
        if(strcmp(getType($<s_val>1), "float32") == 0){
            CODEGEN("fload %d\n", get_address($<s_val>1));
        }
        else if(strcmp(getType($<s_val>1), "int32") == 0){
            CODEGEN("iload %d\n", get_address($<s_val>1));
        }
        else if(strcmp(getType($<s_val>1), "bool") == 0 
                || strcmp(getType($<s_val>1), "string") == 0
                || strcmp(getType($<s_val>1), "char") == 0){ // string or bool or char
            CODEGEN("aload %d\n", get_address($<s_val>1));
        }
    }
    | '(' Expression ')' {
        $<s_val>$ = (getType($<s_val>2));
    }
;

IndexExpr
    : TRUE {
        printf("TRUE 1\n");
        $<s_val>$ = ("bool");
        CODEGEN("iconst_1\n");
    }
    | FALSE {
        printf("FALSE 0\n");
        $<s_val>$ = ("bool");
        CODEGEN("iconst_0\n");
    }
    | 
;

Literal 
    : INT_LIT {
        $<s_val>$ = ("int32"); 
        printf("INT_LIT %d\n", $<i_val>1); 
        CODEGEN("ldc %d\n", $<i_val>1);
    }
    | FLOAT_LIT {
        $<s_val>$ = ("float32"); 
        printf("FLOAT_LIT %f\n", $<f_val>1);
        CODEGEN("ldc %f\n", $<f_val>1);
    }
    | BOOL_LIT {
        $<s_val>$ = ("bool");
        printf("BOOL_LIT %d\n", $<b_val>1);
        CODEGEN("ldc %d\n", $<b_val>1);
    }
    | CHAR_LIT {
        $<s_val>$ = ("char");
        printf("CHAR_LIT %c\n", $<c_val>1);
        CODEGEN("ldc %c\n", $<c_val>1);
    }
    | '"' STRING_LIT '"' {
        $<s_val>$ = ("string");
        printf("STRING_LIT %s\n", $<s_val>2);
        CODEGEN("ldc \"%s\"\n", $<s_val>2); 
    } 
;

IfStmt
    : IF IfCondition IfBlock Else
;

IfCondition
    : Expression {
         if(strcmp("bool", getType($<s_val>1)) != 0){
            printf(error_message, "non-bool (type %s) used as for condition", getType($<s_val>1));
            yyerror(error_message);
            g_has_error = 1;
        }
    }
;

IfBlock
    : IfBlockStart NEWLINE StatementList IfBlockEnd
    | IfBlockStart IfBlockEnd
;

IfBlockStart
    : '{' {
        create_symbol();
    }
;

IfBlockEnd
    : '}' {
        dump_symbol();
    }
;

Else
    : ELSE IfStmt
    | ELSE Block
;

ForStmt
    :{
        forLevel++;
    } MulForStmt NEWLINE {
        forLevel--;
    }
;

MulForStmt
    : FOR {
        forNum++;
        if(forLevel == 1){
            previous_for = forNum;
        }
        else{
            ;
        }
        CODEGEN("L%d_for_begin:\n", forNum); 
    }
    for_condition {
        if(num_of_ForClause != 0){
            if(forLevel == 1){
                CODEGEN("\tgoto L%d_for_Post\n", previous_for); 
            }
            else if(forLevel != 1){
                CODEGEN("\tgoto L%d_for_Post\n", forNum);
            }
        }
        else{
            if(forLevel == 1){
                CODEGEN("\tgoto L%d_for_begin\n", previous_for); 
            }
            else if(forLevel != 1){
                CODEGEN("\tgoto L%d_for_begin\n", forNum); 
            }
        }

        // multi level for loop
        if(forLevel == 1){
            CODEGEN("L%d_for_exit:\n", previous_for); 
        }
        else if(forLevel != 1){
            CODEGEN("L%d_for_exit:\n", forNum);
        }
        num_of_ForClause--;
    }
;

for_condition
    : Expression { // for(x > 0)
        CODEGEN("\tifeq L%d_for_exit \n", forNum); 
    } ForEnd
    | ForClause { // for(int i = 0; i < 10; i++)
        CODEGEN("L%d_for_Block:\n", forNum); 
    } ForEnd
;

ForEnd
    : Block
;

ForClause 
    : SimpleStmt { 
        num_of_ForClause++; 
        CODEGEN("L%d_for_Condition:\n", forNum);
    } ';' Expression { 
        CODEGEN("\tifeq L%d_for_exit \n\tgoto L%d_for_Block \n", forNum, forNum); 
    } ';' { 
        CODEGEN("L%d_for_Post:\n", forNum); 
    } SimpleStmt { 
        CODEGEN("\tgoto L%d_for_Condition \n", forNum); 
    } 
;

InitStmt 
    : SimpleStmt {  
        $<s_val>$ = (getType($<s_val>1));
    }
;

PostStmt 
    : SimpleStmt {  
        $<s_val>$ = (getType($<s_val>1));
    }
;

ConversionExpr 
    : Type '(' Expression ')' {
        printf("%c2%c\n", getType($<s_val>3)[0], getType($<s_val>1)[0]);
        CODEGEN("%c2%c\n", getType($<s_val>3)[0], getType($<s_val>1)[0]);
        $<s_val>$ = (getType($<s_val>1));
    }
;

binary_op 
    : LOR {
        $<s_val>$ = ("LOR");
    }
    | LAND {
        $<s_val>$ = ("LAND");
    }
    | cmp_op {
        $<s_val>$ = (getType($<s_val>1));
    }
    | add_op {
        $<s_val>$ = (getType($<s_val>1));
    }
    | mul_op {
        $<s_val>$ = (getType($<s_val>1));
    }
;

cmp_op 
    : EQL {
        strcpy($<s_val>$, "EQL");
    }
    | NEQ {
        strcpy($<s_val>$, "NEQ");
    }
    | '<' {
        strcpy($<s_val>$, "LSS");
    }
    | LEQ {
        strcpy($<s_val>$, "LEQ");
    }
    | '>' {
        strcpy($<s_val>$, "GTR");
    }
    | GEQ {
        strcpy($<s_val>$, "GEQ");
    }
;

add_op 
    : '+' {
        strcpy($<s_val>$, "ADD");
    }
    | '-' {
        strcpy($<s_val>$, "SUB");
    }
;

mul_op 
    : '*' {
        strcpy($<s_val>$, "MUL");
    }
    | '/' {
        strcpy($<s_val>$, "QUO");
    }
    | '%' {
        strcpy($<s_val>$, "REM");
    }
;

unary_op 
    : '+' {
        $<s_val>$ = ("POS");
    }
    | '-' {
        $<s_val>$ = ("NEG");
    }
    | '!' {
        $<s_val>$ = ("NOT");
    }
;

PrintStmt 
    :  PRINT '(' Expression ')' {
        char tmp[10] = ""; 
        strcpy(tmp, getType($<s_val>3));
        printf("PRINT %s\n", tmp);
        CODEGEN("getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\n");
        if(strcmp(getType($<s_val>3), "int32") == 0){
            CODEGEN("invokevirtual java/io/PrintStream/print(I)V\n");
        }
        else if(strcmp(getType($<s_val>3), "float32") == 0){
            CODEGEN("invokevirtual java/io/PrintStream/print(F)V\n");
        }
        else if(strcmp(getType($<s_val>3), "bool") == 0){
            CODEGEN("invokevirtual java/io/PrintStream/print(Z)V\n");
            // CODEGEN("invokevirtual java/io/PrintStream/print(Ljava/lang/BOOL;)V\n");
        }
        else if(strcmp(getType($<s_val>3), "string") == 0){
            CODEGEN("invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
        }
    }
    | PRINTLN '(' Expression ')' {
        char tmp[10] = ""; 
        strcpy(tmp, getType($<s_val>3));
        printf("PRINTLN %s\n", tmp);
        CODEGEN("getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\n");
        if(strcmp(getType($<s_val>3), "int32") == 0){
            CODEGEN("invokevirtual java/io/PrintStream/println(I)V\n");
        }
        else if(strcmp(getType($<s_val>3), "float32") == 0){
            CODEGEN("invokevirtual java/io/PrintStream/println(F)V\n");
        }
        else if(strcmp(getType($<s_val>3), "bool") == 0){
            CODEGEN("invokevirtual java/io/PrintStream/println(Z)V\n");
            // CODEGEN("invokevirtual java/io/PrintStream/print(Ljava/lang/BOOL;)V\n");
        }
        else if(strcmp(getType($<s_val>3), "string") == 0){
            CODEGEN("invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
        }
    }
;

Block 
    : '{' { 
        create_symbol();
    } StatementList '}' {
        dump_symbol();
    }
;

ReturnStmt 
    : RETURN {
        printf("return\n");
    }
    | RETURN Expression {
        printf("return\n");
    }
;

%%

/* C code section */

void initial(){
    int i = 0;
    while(i < M){
        int j = 0;
        while(j < N){
            symbolTable[i].name[j] = "";
            symbolTable[i].type[j] = "";
            symbolTable[i].addr[j] = -2;
            symbolTable[i].index[j] = -1;
            symbolTable[i].func_sig[j] = "";
            symbolTable[i].lineno[j] = 0;
            symbolTable[i].scope_level[j] = 0;
            j++;
        }
        i++;
    }
}

void initial2(int scope){
    int j = 0;
    while(j < N){
        symbolTable[scope].type[j] = "";
        symbolTable[scope].name[j] = "";
        symbolTable[scope].func_sig[j] = "";
        symbolTable[scope].addr[j] = -2;
        symbolTable[scope].index[j] = -1;
        symbolTable[scope].scope_level[j] = 0;
        symbolTable[scope].lineno[j] = 0;
        j++;
    }
    inside_each_scope_id[scope] = 0;
}

int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }
    if (!yyin) {
        printf("file `%s` doesn't exists or cannot be opened\n", argv[1]);
        exit(1);
    }

    /* Codegen output init */
    char *bytecode_filename = "hw3.j";
    fout = fopen(bytecode_filename, "w");
    CODEGEN(".source hw3.j\n");
    CODEGEN(".class public Main\n");
    CODEGEN(".super java/lang/Object\n");
    CODEGEN(".method public static main([Ljava/lang/String;)V\n");
    CODEGEN(".limit stack 100\n");
    CODEGEN(".limit locals 100\n\n");

    /* Symbol table init */
    // Add your code

    yylineno = 0;
    initial();
    create_symbol(); 
    yyparse();

    /* Symbol table dump */
    // Add your code

	printf("Total lines: %d\n", yylineno);
    CODEGEN("\treturn\n.end method\n");
    fclose(fout);
    fclose(yyin);

    if (g_has_error) {
       remove(bytecode_filename);
    }
    dump_symbol();
    yylex_destroy();
    return 0;
}

static void create_symbol() {     
    printf("> Create symbol table (scope level %d)\n", scopeID++);
}

static void insert_symbol(char *indent, char *type) {
    int id = 0;
    if(first_insert == 0){
        id = scopeID - 1;
    }
    int i = 0;
    while(i < N){
        if(strcmp(indent, symbolTable[scopeID - 1].name[i]) == 0){ // redefine
            printf(error_message, "%s redeclared in this block. previous declaration at line %d",
                    indent, symbolTable[scopeID - 1].lineno[i]);
            yyerror(error_message);
            g_has_error = 1;
        }
        i++;
    }
    if(id >= 0){
        symbolTable[id].type[inside_each_scope_id[id]] = type;
        symbolTable[id].name[inside_each_scope_id[id]] = indent;
        symbolTable[id].addr[inside_each_scope_id[id]] = addr_cnt;
        symbolTable[id].index[inside_each_scope_id[id]] = inside_each_scope_id[id];
        if(strcmp(indent, "main") == 0){
            symbolTable[id].lineno[inside_each_scope_id[id]] = yylineno + 1;
            symbolTable[id].func_sig[inside_each_scope_id[id]] = "()V";
        }
        else if(strcmp(indent, "main") != 0){
            symbolTable[id].lineno[inside_each_scope_id[id]] = yylineno;
            symbolTable[id].func_sig[inside_each_scope_id[id]] = "-";
        }
        printf("> Insert `%s` (addr: %d) to scope level %d\n", indent, addr_cnt, id);
        inside_each_scope_id[id]++;
        addr_cnt++;
        if(first_insert == 1){
            first_insert = 0;
        }
    }
}

static void lookup_symbol(char* indent) {
    int flag = 0;
    int id = scopeID - 1;
    while(id >= 0){
        if(flag != 0){
            break;
        }
        int i = 0;
        while(i < N){
            if(strcmp(indent, symbolTable[id].name[i]) == 0){
                printf("IDENT (name=%s, address=%d)\n", indent,symbolTable[id].addr[i]);
                flag = 1;
                break;
            }
            i++;
        }
        id--;
    }
}

static void dump_symbol() {
    int id = 0;
    if (scopeID == 0){
        id = 0;
    }
    else{
        id = scopeID - 1;
    }
    printf("\n> Dump symbol table (scope level: %d)\n", id);
    printf("%-10s%-10s%-10s%-10s%-10s%-10s\n",
           "Index", "Name", "Type", "Addr", "Lineno", "Func_sig");
    int j = 0;
    while(j < N){
        if(symbolTable[id].index[j] != -1){
            printf("%-10d%-10s%-10s%-10d%-10d%-10s\n",
                    j, symbolTable[id].name[j], symbolTable[id].type[j], symbolTable[id].addr[j],symbolTable[id].lineno[j], symbolTable[id].func_sig[j]);
        }
        j++;
    } 
    printf("\n");
    // reset
    initial2(scopeID - 1);
    scopeID --;
}

char *getType(char *indent){
    if(strcmp("float32", indent) == 0 || strcmp("int32", indent) == 0 
        || strcmp("bool", indent) == 0 || strcmp("string", indent) == 0
        || strcmp("char", indent) == 0){
        return strdup(indent);
    }
    else{
        int i = scopeID - 1;
        while(i >= 0){
            int j = 0;
            while(j < N){
                if(strcmp(indent, symbolTable[i].name[j]) == 0){
                    return strdup(symbolTable[i].type[j]);
                }
                j++;
            }
            i--;
        }
        return strdup("ERROR");
    }
}

int get_address(char *indent){
    int i = scopeID - 1;
    while(i >= 0){
        int j = 0;
        while(j < N){
            if(strcmp(indent, symbolTable[i].name[j]) == 0){
                return symbolTable[i].addr[j];
            }
            j++;
        }
        i--;
    }
    return 0;
}