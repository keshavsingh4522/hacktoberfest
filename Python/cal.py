import ply.lex as lex
import ply.yacc as yacc

# Lexer
tokens = (
    'NUMBER',
    'PLUS',
    'MINUS',
    'TIMES',
    'DIVIDE',
    'LPAREN',
    'RPAREN',
)

t_PLUS = r'\+'
t_MINUS = r'-'
t_TIMES = r'\*'
t_DIVIDE = r'/'
t_LPAREN = r'\('
t_RPAREN = r'\)'

def t_NUMBER(t):
    r'\d+'
    t.value = int(t.value)
    return t

t_ignore = ' \t\n'

def t_error(t):
    print(f"Invalid character: '{t.value[0]}'")
    t.lexer.skip(1)

lexer = lex.lex()

# Parser
def p_expression_binop(p):
    '''
    expression : expression PLUS expression
               | expression MINUS expression
               | expression TIMES expression
               | expression DIVIDE expression
    '''
    if p[2] == '+':
        p[0] = p[1] + p[3]
    elif p[2] == '-':
        p[0] = p[1] - p[3]
    elif p[2] == '*':
        p[0] = p[1] * p[3]
    elif p[2] == '/':
        if p[3] == 0:
            raise ZeroDivisionError("Division by zero")
        p[0] = p[1] / p[3]

def p_expression_group(p):
    '''
    expression : LPAREN expression RPAREN
    '''
    p[0] = p[2]

def p_expression_number(p):
    '''
    expression : NUMBER
    '''
    p[0] = p[1]

def p_error(p):
    print("Syntax error")

parser = yacc.yacc()

# Interactive Calculator
while True:
    try:
        expression = input("Enter an expression: ")
        result = parser.parse(expression)
        print(f"Result: {result}")
    except Exception as e:
        print(f"Error: {e}")
