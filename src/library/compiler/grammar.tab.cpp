// A Bison parser, made by GNU Bison 3.6.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.


// Take the name prefix into account.
#define yylex   grammarlex



#include "grammar.tab.hpp"


// Unqualified %code blocks.
#line 34 "grammar.yy"

#include <iostream>
#include <cstdlib>
#include <fstream>

/* include for all driver functions */
#include "driver.hpp"

#undef yylex
#define yylex scanner.grammarlex

#line 60 "grammar.tab.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 5 "grammar.yy"
namespace LoLa {
#line 153 "grammar.tab.cpp"

  /// Build a parser object.
  LoLaParser::LoLaParser (LoLaScanner  &scanner_yyarg, LoLaDriver  &driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

  LoLaParser::~LoLaParser ()
  {}

  LoLaParser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/

  // basic_symbol.
  template <typename Base>
  LoLaParser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case 62: // expr_0
      case 64: // expr_02
      case 66: // expr_1
      case 68: // expr_2
      case 70: // expr_3
      case 71: // expr_4
      case 72: // rvalue
      case 73: // call
      case 74: // array
        value.copy< Expression > (YY_MOVE (that.value));
        break;

      case 49: // function
        value.copy< Function > (YY_MOVE (that.value));
        break;

      case 76: // lvalue
        value.copy< LValueExpression > (YY_MOVE (that.value));
        break;

      case 75: // arglist
        value.copy< List<Expression> > (YY_MOVE (that.value));
        break;

      case 52: // stmtlist
        value.copy< List<Statement> > (YY_MOVE (that.value));
        break;

      case 50: // plist
        value.copy< List<std::string> > (YY_MOVE (that.value));
        break;

      case 20: // LEQUAL
      case 21: // GEQUAL
      case 22: // EQUALS
      case 23: // DIFFERS
      case 24: // LESS
      case 25: // MORE
      case 35: // INVERT
      case 36: // PLUS
      case 37: // MINUS
      case 38: // MULT
      case 39: // DIV
      case 40: // MOD
      case 41: // AND
      case 42: // OR
      case 61: // expr_0_op
      case 63: // expr_02_op
      case 65: // expr_1_op
      case 67: // expr_2_op
      case 69: // expr_3_op
        value.copy< Operator > (YY_MOVE (that.value));
        break;

      case 48: // program
        value.copy< Program > (YY_MOVE (that.value));
        break;

      case 51: // body
      case 53: // statement
      case 54: // decl
      case 55: // ass
      case 56: // for
      case 57: // while
      case 58: // return
      case 59: // conditional
      case 60: // expression
        value.copy< Statement > (YY_MOVE (that.value));
        break;

      case 43: // IDENT
      case 44: // NUMBER
      case 45: // STRING
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  LoLaParser::symbol_kind_type
  LoLaParser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

  template <typename Base>
  bool
  LoLaParser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  LoLaParser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case 62: // expr_0
      case 64: // expr_02
      case 66: // expr_1
      case 68: // expr_2
      case 70: // expr_3
      case 71: // expr_4
      case 72: // rvalue
      case 73: // call
      case 74: // array
        value.move< Expression > (YY_MOVE (s.value));
        break;

      case 49: // function
        value.move< Function > (YY_MOVE (s.value));
        break;

      case 76: // lvalue
        value.move< LValueExpression > (YY_MOVE (s.value));
        break;

      case 75: // arglist
        value.move< List<Expression> > (YY_MOVE (s.value));
        break;

      case 52: // stmtlist
        value.move< List<Statement> > (YY_MOVE (s.value));
        break;

      case 50: // plist
        value.move< List<std::string> > (YY_MOVE (s.value));
        break;

      case 20: // LEQUAL
      case 21: // GEQUAL
      case 22: // EQUALS
      case 23: // DIFFERS
      case 24: // LESS
      case 25: // MORE
      case 35: // INVERT
      case 36: // PLUS
      case 37: // MINUS
      case 38: // MULT
      case 39: // DIV
      case 40: // MOD
      case 41: // AND
      case 42: // OR
      case 61: // expr_0_op
      case 63: // expr_02_op
      case 65: // expr_1_op
      case 67: // expr_2_op
      case 69: // expr_3_op
        value.move< Operator > (YY_MOVE (s.value));
        break;

      case 48: // program
        value.move< Program > (YY_MOVE (s.value));
        break;

      case 51: // body
      case 53: // statement
      case 54: // decl
      case 55: // ass
      case 56: // for
      case 57: // while
      case 58: // return
      case 59: // conditional
      case 60: // expression
        value.move< Statement > (YY_MOVE (s.value));
        break;

      case 43: // IDENT
      case 44: // NUMBER
      case 45: // STRING
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  LoLaParser::by_kind::by_kind ()
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  LoLaParser::by_kind::by_kind (by_kind&& that)
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  LoLaParser::by_kind::by_kind (const by_kind& that)
    : kind_ (that.kind_)
  {}

  LoLaParser::by_kind::by_kind (token_kind_type t)
    : kind_ (yytranslate_ (t))
  {}

  void
  LoLaParser::by_kind::clear ()
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  LoLaParser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  LoLaParser::symbol_kind_type
  LoLaParser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }

  LoLaParser::symbol_kind_type
  LoLaParser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  // by_state.
  LoLaParser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  LoLaParser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  LoLaParser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  LoLaParser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  LoLaParser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  LoLaParser::symbol_kind_type
  LoLaParser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  LoLaParser::stack_symbol_type::stack_symbol_type ()
  {}

  LoLaParser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case 62: // expr_0
      case 64: // expr_02
      case 66: // expr_1
      case 68: // expr_2
      case 70: // expr_3
      case 71: // expr_4
      case 72: // rvalue
      case 73: // call
      case 74: // array
        value.YY_MOVE_OR_COPY< Expression > (YY_MOVE (that.value));
        break;

      case 49: // function
        value.YY_MOVE_OR_COPY< Function > (YY_MOVE (that.value));
        break;

      case 76: // lvalue
        value.YY_MOVE_OR_COPY< LValueExpression > (YY_MOVE (that.value));
        break;

      case 75: // arglist
        value.YY_MOVE_OR_COPY< List<Expression> > (YY_MOVE (that.value));
        break;

      case 52: // stmtlist
        value.YY_MOVE_OR_COPY< List<Statement> > (YY_MOVE (that.value));
        break;

      case 50: // plist
        value.YY_MOVE_OR_COPY< List<std::string> > (YY_MOVE (that.value));
        break;

      case 20: // LEQUAL
      case 21: // GEQUAL
      case 22: // EQUALS
      case 23: // DIFFERS
      case 24: // LESS
      case 25: // MORE
      case 35: // INVERT
      case 36: // PLUS
      case 37: // MINUS
      case 38: // MULT
      case 39: // DIV
      case 40: // MOD
      case 41: // AND
      case 42: // OR
      case 61: // expr_0_op
      case 63: // expr_02_op
      case 65: // expr_1_op
      case 67: // expr_2_op
      case 69: // expr_3_op
        value.YY_MOVE_OR_COPY< Operator > (YY_MOVE (that.value));
        break;

      case 48: // program
        value.YY_MOVE_OR_COPY< Program > (YY_MOVE (that.value));
        break;

      case 51: // body
      case 53: // statement
      case 54: // decl
      case 55: // ass
      case 56: // for
      case 57: // while
      case 58: // return
      case 59: // conditional
      case 60: // expression
        value.YY_MOVE_OR_COPY< Statement > (YY_MOVE (that.value));
        break;

      case 43: // IDENT
      case 44: // NUMBER
      case 45: // STRING
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  LoLaParser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case 62: // expr_0
      case 64: // expr_02
      case 66: // expr_1
      case 68: // expr_2
      case 70: // expr_3
      case 71: // expr_4
      case 72: // rvalue
      case 73: // call
      case 74: // array
        value.move< Expression > (YY_MOVE (that.value));
        break;

      case 49: // function
        value.move< Function > (YY_MOVE (that.value));
        break;

      case 76: // lvalue
        value.move< LValueExpression > (YY_MOVE (that.value));
        break;

      case 75: // arglist
        value.move< List<Expression> > (YY_MOVE (that.value));
        break;

      case 52: // stmtlist
        value.move< List<Statement> > (YY_MOVE (that.value));
        break;

      case 50: // plist
        value.move< List<std::string> > (YY_MOVE (that.value));
        break;

      case 20: // LEQUAL
      case 21: // GEQUAL
      case 22: // EQUALS
      case 23: // DIFFERS
      case 24: // LESS
      case 25: // MORE
      case 35: // INVERT
      case 36: // PLUS
      case 37: // MINUS
      case 38: // MULT
      case 39: // DIV
      case 40: // MOD
      case 41: // AND
      case 42: // OR
      case 61: // expr_0_op
      case 63: // expr_02_op
      case 65: // expr_1_op
      case 67: // expr_2_op
      case 69: // expr_3_op
        value.move< Operator > (YY_MOVE (that.value));
        break;

      case 48: // program
        value.move< Program > (YY_MOVE (that.value));
        break;

      case 51: // body
      case 53: // statement
      case 54: // decl
      case 55: // ass
      case 56: // for
      case 57: // while
      case 58: // return
      case 59: // conditional
      case 60: // expression
        value.move< Statement > (YY_MOVE (that.value));
        break;

      case 43: // IDENT
      case 44: // NUMBER
      case 45: // STRING
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  LoLaParser::stack_symbol_type&
  LoLaParser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case 62: // expr_0
      case 64: // expr_02
      case 66: // expr_1
      case 68: // expr_2
      case 70: // expr_3
      case 71: // expr_4
      case 72: // rvalue
      case 73: // call
      case 74: // array
        value.copy< Expression > (that.value);
        break;

      case 49: // function
        value.copy< Function > (that.value);
        break;

      case 76: // lvalue
        value.copy< LValueExpression > (that.value);
        break;

      case 75: // arglist
        value.copy< List<Expression> > (that.value);
        break;

      case 52: // stmtlist
        value.copy< List<Statement> > (that.value);
        break;

      case 50: // plist
        value.copy< List<std::string> > (that.value);
        break;

      case 20: // LEQUAL
      case 21: // GEQUAL
      case 22: // EQUALS
      case 23: // DIFFERS
      case 24: // LESS
      case 25: // MORE
      case 35: // INVERT
      case 36: // PLUS
      case 37: // MINUS
      case 38: // MULT
      case 39: // DIV
      case 40: // MOD
      case 41: // AND
      case 42: // OR
      case 61: // expr_0_op
      case 63: // expr_02_op
      case 65: // expr_1_op
      case 67: // expr_2_op
      case 69: // expr_3_op
        value.copy< Operator > (that.value);
        break;

      case 48: // program
        value.copy< Program > (that.value);
        break;

      case 51: // body
      case 53: // statement
      case 54: // decl
      case 55: // ass
      case 56: // for
      case 57: // while
      case 58: // return
      case 59: // conditional
      case 60: // expression
        value.copy< Statement > (that.value);
        break;

      case 43: // IDENT
      case 44: // NUMBER
      case 45: // STRING
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  LoLaParser::stack_symbol_type&
  LoLaParser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case 62: // expr_0
      case 64: // expr_02
      case 66: // expr_1
      case 68: // expr_2
      case 70: // expr_3
      case 71: // expr_4
      case 72: // rvalue
      case 73: // call
      case 74: // array
        value.move< Expression > (that.value);
        break;

      case 49: // function
        value.move< Function > (that.value);
        break;

      case 76: // lvalue
        value.move< LValueExpression > (that.value);
        break;

      case 75: // arglist
        value.move< List<Expression> > (that.value);
        break;

      case 52: // stmtlist
        value.move< List<Statement> > (that.value);
        break;

      case 50: // plist
        value.move< List<std::string> > (that.value);
        break;

      case 20: // LEQUAL
      case 21: // GEQUAL
      case 22: // EQUALS
      case 23: // DIFFERS
      case 24: // LESS
      case 25: // MORE
      case 35: // INVERT
      case 36: // PLUS
      case 37: // MINUS
      case 38: // MULT
      case 39: // DIV
      case 40: // MOD
      case 41: // AND
      case 42: // OR
      case 61: // expr_0_op
      case 63: // expr_02_op
      case 65: // expr_1_op
      case 67: // expr_2_op
      case 69: // expr_3_op
        value.move< Operator > (that.value);
        break;

      case 48: // program
        value.move< Program > (that.value);
        break;

      case 51: // body
      case 53: // statement
      case 54: // decl
      case 55: // ass
      case 56: // for
      case 57: // while
      case 58: // return
      case 59: // conditional
      case 60: // expression
        value.move< Statement > (that.value);
        break;

      case 43: // IDENT
      case 44: // NUMBER
      case 45: // STRING
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  LoLaParser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  LoLaParser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YYUSE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  LoLaParser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  LoLaParser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  LoLaParser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  LoLaParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  LoLaParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  LoLaParser::debug_level_type
  LoLaParser::debug_level () const
  {
    return yydebug_;
  }

  void
  LoLaParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  LoLaParser::state_type
  LoLaParser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  LoLaParser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  LoLaParser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  LoLaParser::operator() ()
  {
    return parse ();
  }

  int
  LoLaParser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 62: // expr_0
      case 64: // expr_02
      case 66: // expr_1
      case 68: // expr_2
      case 70: // expr_3
      case 71: // expr_4
      case 72: // rvalue
      case 73: // call
      case 74: // array
        yylhs.value.emplace< Expression > ();
        break;

      case 49: // function
        yylhs.value.emplace< Function > ();
        break;

      case 76: // lvalue
        yylhs.value.emplace< LValueExpression > ();
        break;

      case 75: // arglist
        yylhs.value.emplace< List<Expression> > ();
        break;

      case 52: // stmtlist
        yylhs.value.emplace< List<Statement> > ();
        break;

      case 50: // plist
        yylhs.value.emplace< List<std::string> > ();
        break;

      case 20: // LEQUAL
      case 21: // GEQUAL
      case 22: // EQUALS
      case 23: // DIFFERS
      case 24: // LESS
      case 25: // MORE
      case 35: // INVERT
      case 36: // PLUS
      case 37: // MINUS
      case 38: // MULT
      case 39: // DIV
      case 40: // MOD
      case 41: // AND
      case 42: // OR
      case 61: // expr_0_op
      case 63: // expr_02_op
      case 65: // expr_1_op
      case 67: // expr_2_op
      case 69: // expr_3_op
        yylhs.value.emplace< Operator > ();
        break;

      case 48: // program
        yylhs.value.emplace< Program > ();
        break;

      case 51: // body
      case 53: // statement
      case 54: // decl
      case 55: // ass
      case 56: // for
      case 57: // while
      case 58: // return
      case 59: // conditional
      case 60: // expression
        yylhs.value.emplace< Statement > ();
        break;

      case 43: // IDENT
      case 44: // NUMBER
      case 45: // STRING
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 83 "grammar.yy"
                       { driver.program = move(yystack_[0].value.as < Program > ()); }
#line 1169 "grammar.tab.cpp"
    break;

  case 3:
#line 85 "grammar.yy"
              { }
#line 1175 "grammar.tab.cpp"
    break;

  case 4:
#line 86 "grammar.yy"
                               {
                yylhs.value.as < Program > () = move(yystack_[1].value.as < Program > ());
                yylhs.value.as < Program > ().functions.emplace_back(move(yystack_[0].value.as < Function > ()));
            }
#line 1184 "grammar.tab.cpp"
    break;

  case 5:
#line 90 "grammar.yy"
                                {
                yylhs.value.as < Program > () = move(yystack_[1].value.as < Program > ());
                yylhs.value.as < Program > ().statements.emplace_back(move(yystack_[0].value.as < Statement > ()));
            }
#line 1193 "grammar.tab.cpp"
    break;

  case 6:
#line 96 "grammar.yy"
                                                        {
                yylhs.value.as < Function > ().name = yystack_[4].value.as < std::string > ();
                yylhs.value.as < Function > ().params = yystack_[2].value.as < List<std::string> > ();
                yylhs.value.as < Function > ().body = move(yystack_[0].value.as < Statement > ());
            }
#line 1203 "grammar.tab.cpp"
    break;

  case 7:
#line 101 "grammar.yy"
                                                  {
                yylhs.value.as < Function > ().name = yystack_[3].value.as < std::string > ();
                yylhs.value.as < Function > ().body = move(yystack_[0].value.as < Statement > ());
            }
#line 1212 "grammar.tab.cpp"
    break;

  case 8:
#line 108 "grammar.yy"
            {
                yylhs.value.as < List<std::string> > ().emplace_back(move(yystack_[0].value.as < std::string > ()));
            }
#line 1220 "grammar.tab.cpp"
    break;

  case 9:
#line 112 "grammar.yy"
            {
                yylhs.value.as < List<std::string> > () = move(yystack_[2].value.as < List<std::string> > ());
                yylhs.value.as < List<std::string> > ().emplace_back(move(yystack_[0].value.as < std::string > ()));
            }
#line 1229 "grammar.tab.cpp"
    break;

  case 10:
#line 118 "grammar.yy"
                                            { yylhs.value.as < Statement > () = SubScope(move(yystack_[1].value.as < List<Statement> > ())); }
#line 1235 "grammar.tab.cpp"
    break;

  case 11:
#line 121 "grammar.yy"
              { }
#line 1241 "grammar.tab.cpp"
    break;

  case 12:
#line 122 "grammar.yy"
                                 {
                yylhs.value.as < List<Statement> > () = move(yystack_[1].value.as < List<Statement> > ());
                yylhs.value.as < List<Statement> > ().emplace_back(move(yystack_[0].value.as < Statement > ()));
            }
#line 1250 "grammar.tab.cpp"
    break;

  case 13:
#line 128 "grammar.yy"
                                  { yylhs.value.as < Statement > () = move(yystack_[0].value.as < Statement > ()); }
#line 1256 "grammar.tab.cpp"
    break;

  case 14:
#line 129 "grammar.yy"
                                  { yylhs.value.as < Statement > () = move(yystack_[0].value.as < Statement > ()); }
#line 1262 "grammar.tab.cpp"
    break;

  case 15:
#line 130 "grammar.yy"
                                  { yylhs.value.as < Statement > () = move(yystack_[0].value.as < Statement > ()); }
#line 1268 "grammar.tab.cpp"
    break;

  case 16:
#line 131 "grammar.yy"
                                  { yylhs.value.as < Statement > () = move(yystack_[0].value.as < Statement > ()); }
#line 1274 "grammar.tab.cpp"
    break;

  case 17:
#line 132 "grammar.yy"
                                  { yylhs.value.as < Statement > () = move(yystack_[0].value.as < Statement > ()); }
#line 1280 "grammar.tab.cpp"
    break;

  case 18:
#line 133 "grammar.yy"
                                  { yylhs.value.as < Statement > () = move(yystack_[0].value.as < Statement > ()); }
#line 1286 "grammar.tab.cpp"
    break;

  case 19:
#line 134 "grammar.yy"
                                  { yylhs.value.as < Statement > () = move(yystack_[0].value.as < Statement > ()); }
#line 1292 "grammar.tab.cpp"
    break;

  case 20:
#line 135 "grammar.yy"
                                  { yylhs.value.as < Statement > () = move(yystack_[0].value.as < Statement > ()); }
#line 1298 "grammar.tab.cpp"
    break;

  case 21:
#line 136 "grammar.yy"
                                  { yylhs.value.as < Statement > () = BreakStatement(); }
#line 1304 "grammar.tab.cpp"
    break;

  case 22:
#line 137 "grammar.yy"
                                  { yylhs.value.as < Statement > () = ContinueStatement(); }
#line 1310 "grammar.tab.cpp"
    break;

  case 23:
#line 140 "grammar.yy"
                                                                { yylhs.value.as < Statement > () = Declaration(move(yystack_[3].value.as < std::string > ()), move(yystack_[1].value.as < Expression > ())); }
#line 1316 "grammar.tab.cpp"
    break;

  case 24:
#line 141 "grammar.yy"
                                                                                { yylhs.value.as < Statement > () = Declaration(move(yystack_[1].value.as < std::string > ())); }
#line 1322 "grammar.tab.cpp"
    break;

  case 25:
#line 142 "grammar.yy"
                                                                        { yylhs.value.as < Statement > () = ExternDeclaration(move(yystack_[1].value.as < std::string > ())); }
#line 1328 "grammar.tab.cpp"
    break;

  case 26:
#line 145 "grammar.yy"
                                                         { yylhs.value.as < Statement > () = Assignment(move(yystack_[3].value.as < LValueExpression > ()), move(yystack_[1].value.as < Expression > ())); }
#line 1334 "grammar.tab.cpp"
    break;

  case 27:
#line 146 "grammar.yy"
                                                         { auto dup = yystack_[3].value.as < LValueExpression > ()->clone(); yylhs.value.as < Statement > () = Assignment(move(yystack_[3].value.as < LValueExpression > ()), BinaryOperator(Operator::Plus, move(dup), move(yystack_[1].value.as < Expression > ()))); }
#line 1340 "grammar.tab.cpp"
    break;

  case 28:
#line 147 "grammar.yy"
                                                         { auto dup = yystack_[3].value.as < LValueExpression > ()->clone(); yylhs.value.as < Statement > () = Assignment(move(yystack_[3].value.as < LValueExpression > ()), BinaryOperator(Operator::Minus, move(dup), move(yystack_[1].value.as < Expression > ()))); }
#line 1346 "grammar.tab.cpp"
    break;

  case 29:
#line 148 "grammar.yy"
                                                         { auto dup = yystack_[3].value.as < LValueExpression > ()->clone(); yylhs.value.as < Statement > () = Assignment(move(yystack_[3].value.as < LValueExpression > ()), BinaryOperator(Operator::Multiply, move(dup), move(yystack_[1].value.as < Expression > ()))); }
#line 1352 "grammar.tab.cpp"
    break;

  case 30:
#line 149 "grammar.yy"
                                                         { auto dup = yystack_[3].value.as < LValueExpression > ()->clone(); yylhs.value.as < Statement > () = Assignment(move(yystack_[3].value.as < LValueExpression > ()), BinaryOperator(Operator::Divide, move(dup), move(yystack_[1].value.as < Expression > ()))); }
#line 1358 "grammar.tab.cpp"
    break;

  case 31:
#line 150 "grammar.yy"
                                                         { auto dup = yystack_[3].value.as < LValueExpression > ()->clone(); yylhs.value.as < Statement > () = Assignment(move(yystack_[3].value.as < LValueExpression > ()), BinaryOperator(Operator::Modulus, move(dup), move(yystack_[1].value.as < Expression > ()))); }
#line 1364 "grammar.tab.cpp"
    break;

  case 32:
#line 153 "grammar.yy"
                                                                    { yylhs.value.as < Statement > () = ForLoop(yystack_[4].value.as < std::string > (),move(yystack_[2].value.as < Expression > ()),move(yystack_[0].value.as < Statement > ())); }
#line 1370 "grammar.tab.cpp"
    break;

  case 33:
#line 156 "grammar.yy"
                                                            { yylhs.value.as < Statement > () = WhileLoop(move(yystack_[2].value.as < Expression > ()), move(yystack_[0].value.as < Statement > ())); }
#line 1376 "grammar.tab.cpp"
    break;

  case 34:
#line 159 "grammar.yy"
                                                                                { yylhs.value.as < Statement > () = Return(move(yystack_[1].value.as < Expression > ())); }
#line 1382 "grammar.tab.cpp"
    break;

  case 35:
#line 160 "grammar.yy"
                                                                                { yylhs.value.as < Statement > () = Return(); }
#line 1388 "grammar.tab.cpp"
    break;

  case 36:
#line 163 "grammar.yy"
                                                                  { yylhs.value.as < Statement > () = IfElse(move(yystack_[4].value.as < Expression > ()), move(yystack_[2].value.as < Statement > ()), move(yystack_[0].value.as < Statement > ())); }
#line 1394 "grammar.tab.cpp"
    break;

  case 37:
#line 164 "grammar.yy"
                                                                        { yylhs.value.as < Statement > () = IfElse(move(yystack_[2].value.as < Expression > ()), move(yystack_[0].value.as < Statement > ())); }
#line 1400 "grammar.tab.cpp"
    break;

  case 38:
#line 167 "grammar.yy"
                                                                                        { yylhs.value.as < Statement > () = DiscardResult(move(yystack_[1].value.as < Expression > ())); }
#line 1406 "grammar.tab.cpp"
    break;

  case 39:
#line 170 "grammar.yy"
                  { yylhs.value.as < Operator > () = yystack_[0].value.as < Operator > (); }
#line 1412 "grammar.tab.cpp"
    break;

  case 40:
#line 170 "grammar.yy"
                        { yylhs.value.as < Operator > () = yystack_[0].value.as < Operator > (); }
#line 1418 "grammar.tab.cpp"
    break;

  case 41:
#line 171 "grammar.yy"
                                                            { yylhs.value.as < Expression > () = BinaryOperator(yystack_[1].value.as < Operator > (), move(yystack_[2].value.as < Expression > ()), move(yystack_[0].value.as < Expression > ())); }
#line 1424 "grammar.tab.cpp"
    break;

  case 42:
#line 172 "grammar.yy"
                                                        { yylhs.value.as < Expression > () = move(yystack_[0].value.as < Expression > ()); }
#line 1430 "grammar.tab.cpp"
    break;

  case 43:
#line 175 "grammar.yy"
                  { yylhs.value.as < Operator > () = yystack_[0].value.as < Operator > (); }
#line 1436 "grammar.tab.cpp"
    break;

  case 44:
#line 175 "grammar.yy"
                         { yylhs.value.as < Operator > () = yystack_[0].value.as < Operator > (); }
#line 1442 "grammar.tab.cpp"
    break;

  case 45:
#line 175 "grammar.yy"
                                 { yylhs.value.as < Operator > () = yystack_[0].value.as < Operator > (); }
#line 1448 "grammar.tab.cpp"
    break;

  case 46:
#line 175 "grammar.yy"
                                        { yylhs.value.as < Operator > () = yystack_[0].value.as < Operator > (); }
#line 1454 "grammar.tab.cpp"
    break;

  case 47:
#line 175 "grammar.yy"
                                               { yylhs.value.as < Operator > () = yystack_[0].value.as < Operator > (); }
#line 1460 "grammar.tab.cpp"
    break;

  case 48:
#line 175 "grammar.yy"
                                                    { yylhs.value.as < Operator > () = yystack_[0].value.as < Operator > (); }
#line 1466 "grammar.tab.cpp"
    break;

  case 49:
#line 176 "grammar.yy"
                                                            { yylhs.value.as < Expression > () = BinaryOperator(yystack_[1].value.as < Operator > (), move(yystack_[2].value.as < Expression > ()), move(yystack_[0].value.as < Expression > ())); }
#line 1472 "grammar.tab.cpp"
    break;

  case 50:
#line 177 "grammar.yy"
                                                        { yylhs.value.as < Expression > () = move(yystack_[0].value.as < Expression > ()); }
#line 1478 "grammar.tab.cpp"
    break;

  case 51:
#line 181 "grammar.yy"
                  { yylhs.value.as < Operator > () = yystack_[0].value.as < Operator > (); }
#line 1484 "grammar.tab.cpp"
    break;

  case 52:
#line 181 "grammar.yy"
                         { yylhs.value.as < Operator > () = yystack_[0].value.as < Operator > (); }
#line 1490 "grammar.tab.cpp"
    break;

  case 53:
#line 182 "grammar.yy"
                                                                                { yylhs.value.as < Expression > () = BinaryOperator(yystack_[1].value.as < Operator > (), move(yystack_[2].value.as < Expression > ()), move(yystack_[0].value.as < Expression > ())); }
#line 1496 "grammar.tab.cpp"
    break;

  case 54:
#line 183 "grammar.yy"
                                                                                        { yylhs.value.as < Expression > () = move(yystack_[0].value.as < Expression > ()); }
#line 1502 "grammar.tab.cpp"
    break;

  case 55:
#line 187 "grammar.yy"
                  { yylhs.value.as < Operator > () = yystack_[0].value.as < Operator > (); }
#line 1508 "grammar.tab.cpp"
    break;

  case 56:
#line 187 "grammar.yy"
                         { yylhs.value.as < Operator > () = yystack_[0].value.as < Operator > (); }
#line 1514 "grammar.tab.cpp"
    break;

  case 57:
#line 187 "grammar.yy"
                               { yylhs.value.as < Operator > () = yystack_[0].value.as < Operator > (); }
#line 1520 "grammar.tab.cpp"
    break;

  case 58:
#line 188 "grammar.yy"
                                                                                { yylhs.value.as < Expression > () = BinaryOperator(yystack_[1].value.as < Operator > (), move(yystack_[2].value.as < Expression > ()), move(yystack_[0].value.as < Expression > ())); }
#line 1526 "grammar.tab.cpp"
    break;

  case 59:
#line 189 "grammar.yy"
                                                                                        { yylhs.value.as < Expression > () = move(yystack_[0].value.as < Expression > ()); }
#line 1532 "grammar.tab.cpp"
    break;

  case 60:
#line 193 "grammar.yy"
                  { yylhs.value.as < Operator > () = yystack_[0].value.as < Operator > (); }
#line 1538 "grammar.tab.cpp"
    break;

  case 61:
#line 193 "grammar.yy"
                          { yylhs.value.as < Operator > () = yystack_[0].value.as < Operator > (); }
#line 1544 "grammar.tab.cpp"
    break;

  case 62:
#line 194 "grammar.yy"
                                                                                        { yylhs.value.as < Expression > () = UnaryOperator(yystack_[1].value.as < Operator > (), move(yystack_[0].value.as < Expression > ())); }
#line 1550 "grammar.tab.cpp"
    break;

  case 63:
#line 195 "grammar.yy"
                                                                                        { yylhs.value.as < Expression > () = move(yystack_[0].value.as < Expression > ()); }
#line 1556 "grammar.tab.cpp"
    break;

  case 64:
#line 199 "grammar.yy"
                                                                                { yylhs.value.as < Expression > () = move(yystack_[1].value.as < Expression > ()); }
#line 1562 "grammar.tab.cpp"
    break;

  case 65:
#line 200 "grammar.yy"
                                                                                        { yylhs.value.as < Expression > () = move(yystack_[0].value.as < Expression > ()); }
#line 1568 "grammar.tab.cpp"
    break;

  case 66:
#line 201 "grammar.yy"
                                                                                        { yylhs.value.as < Expression > () = move(yystack_[0].value.as < LValueExpression > ()); }
#line 1574 "grammar.tab.cpp"
    break;

  case 67:
#line 204 "grammar.yy"
                                                                                                { yylhs.value.as < Expression > () = move(yystack_[0].value.as < Expression > ()); }
#line 1580 "grammar.tab.cpp"
    break;

  case 68:
#line 205 "grammar.yy"
                                                                                                { yylhs.value.as < Expression > () = move(yystack_[0].value.as < Expression > ()); }
#line 1586 "grammar.tab.cpp"
    break;

  case 69:
#line 206 "grammar.yy"
                                                                                        { yylhs.value.as < Expression > () = StringLiteral(yystack_[0].value.as < std::string > ()); }
#line 1592 "grammar.tab.cpp"
    break;

  case 70:
#line 207 "grammar.yy"
                                                                                        { yylhs.value.as < Expression > () = NumberLiteral(yystack_[0].value.as < std::string > ()); }
#line 1598 "grammar.tab.cpp"
    break;

  case 71:
#line 210 "grammar.yy"
                                                                        { yylhs.value.as < Expression > () = MethodCall(move(yystack_[4].value.as < Expression > ()), yystack_[2].value.as < std::string > (), {}); }
#line 1604 "grammar.tab.cpp"
    break;

  case 72:
#line 211 "grammar.yy"
                                                        { yylhs.value.as < Expression > () = MethodCall(move(yystack_[5].value.as < Expression > ()), yystack_[3].value.as < std::string > (), move(yystack_[1].value.as < List<Expression> > ())); }
#line 1610 "grammar.tab.cpp"
    break;

  case 73:
#line 212 "grammar.yy"
                                                                                { yylhs.value.as < Expression > () = FunctionCall(yystack_[2].value.as < std::string > (), {}); }
#line 1616 "grammar.tab.cpp"
    break;

  case 74:
#line 213 "grammar.yy"
                                                                        { yylhs.value.as < Expression > () = FunctionCall(yystack_[3].value.as < std::string > (), move(yystack_[1].value.as < List<Expression> > ())); }
#line 1622 "grammar.tab.cpp"
    break;

  case 75:
#line 216 "grammar.yy"
                                                                                        { yylhs.value.as < Expression > () = ArrayLiteral({}); }
#line 1628 "grammar.tab.cpp"
    break;

  case 76:
#line 217 "grammar.yy"
                                                                        { yylhs.value.as < Expression > () = ArrayLiteral(move(yystack_[1].value.as < List<Expression> > ())); }
#line 1634 "grammar.tab.cpp"
    break;

  case 77:
#line 220 "grammar.yy"
                                   {
                yylhs.value.as < List<Expression> > () = move(yystack_[2].value.as < List<Expression> > ());
                yylhs.value.as < List<Expression> > ().emplace_back(move(yystack_[0].value.as < Expression > ()));
            }
#line 1643 "grammar.tab.cpp"
    break;

  case 78:
#line 224 "grammar.yy"
                     {
                yylhs.value.as < List<Expression> > ().emplace_back(move(yystack_[0].value.as < Expression > ()));
            }
#line 1651 "grammar.tab.cpp"
    break;

  case 79:
#line 229 "grammar.yy"
                                                        { yylhs.value.as < LValueExpression > () = ArrayIndexer(move(yystack_[3].value.as < Expression > ()), move(yystack_[1].value.as < Expression > ())); }
#line 1657 "grammar.tab.cpp"
    break;

  case 80:
#line 230 "grammar.yy"
                                                        { yylhs.value.as < LValueExpression > () = VariableRef(yystack_[0].value.as < std::string > ()); }
#line 1663 "grammar.tab.cpp"
    break;


#line 1667 "grammar.tab.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  LoLaParser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  LoLaParser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0





  const signed char LoLaParser::yypact_ninf_ = -101;

  const signed char LoLaParser::yytable_ninf_ = -1;

  const short
  LoLaParser::yypact_[] =
  {
    -101,     5,    32,  -101,  -101,   183,    17,   -28,    -5,    18,
      54,    78,    41,    57,    59,   158,    84,  -101,  -101,  -101,
    -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,     4,
    -101,    62,  -101,   199,   117,  -101,  -101,    23,   214,   -24,
      66,   183,  -101,     4,  -101,  -101,  -101,   -21,     2,   -20,
      71,    64,   183,   183,    94,  -101,  -101,  -101,   -15,   131,
     183,    72,  -101,   183,   183,   183,   183,   183,   183,  -101,
    -101,  -101,  -101,  -101,   183,  -101,  -101,  -101,  -101,  -101,
    -101,   183,  -101,  -101,   183,  -101,  -101,  -101,   183,  -101,
    -101,   183,   183,  -101,  -101,     9,    40,    51,    10,  -101,
    -101,    52,    70,   108,    56,    61,   129,   144,   163,   169,
     214,   -24,    66,  -101,   -21,   171,   183,   111,   139,   111,
    -101,    68,  -101,  -101,   172,  -101,  -101,  -101,  -101,  -101,
    -101,  -101,    67,  -101,   109,  -101,   111,    82,  -101,    73,
     111,   139,  -101,  -101,  -101,  -101,  -101
  };

  const signed char
  LoLaParser::yydefact_[] =
  {
       3,     0,     2,     1,    11,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    80,    70,    69,     4,
      20,     5,    13,    14,    15,    16,    19,    17,    18,     0,
      65,    67,    68,    66,     0,    61,    60,     0,    42,    50,
      54,     0,    59,    63,    67,    66,    75,    78,     0,     0,
       0,     0,     0,     0,     0,    21,    22,    35,     0,     0,
       0,     0,    38,     0,     0,     0,     0,     0,     0,    10,
      12,    64,    39,    40,     0,    45,    46,    43,    44,    48,
      47,     0,    51,    52,     0,    55,    56,    57,     0,    62,
      76,     0,     0,    24,    25,     0,     0,     0,     0,    34,
      73,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      41,    49,    53,    58,    77,     0,     0,     0,     0,     0,
       8,     0,    74,    79,     0,    26,    27,    28,    29,    30,
      31,    23,     0,    33,    37,     7,     0,     0,    71,     0,
       0,     0,     6,     9,    72,    32,    36
  };

  const signed char
  LoLaParser::yypgoto_[] =
  {
    -101,  -101,  -101,  -101,  -101,  -100,  -101,   -31,  -101,  -101,
    -101,  -101,  -101,  -101,  -101,  -101,     3,  -101,    58,  -101,
      50,  -101,    63,  -101,   -37,    -2,  -101,    -1,  -101,   -52,
       0
  };

  const signed char
  LoLaParser::yydefgoto_[] =
  {
      -1,     1,     2,    19,   121,    20,    34,    21,    22,    23,
      24,    25,    26,    27,    28,    74,    47,    81,    38,    84,
      39,    88,    40,    41,    42,    43,    30,    44,    32,    48,
      45
  };

  const unsigned char
  LoLaParser::yytable_[] =
  {
      29,    31,    33,    70,    89,     3,    92,   101,    37,    93,
      90,    60,    82,    83,    99,    49,   119,   133,    58,   135,
      72,    73,     5,    51,     6,    46,    72,    73,   116,    71,
      91,    61,    29,    31,    33,     4,   142,     5,    50,     6,
     145,     7,     8,     9,    10,    11,   117,    12,    13,    14,
      15,   113,    35,   120,    36,    96,    97,   118,   122,    52,
      16,    17,    18,   102,    72,    73,   104,   105,   106,   107,
     108,   109,   139,   140,   136,    16,    17,    18,   123,   144,
      91,    72,    73,    53,    54,   125,    55,   134,    56,    59,
     126,    62,    72,    73,   114,   115,   137,    72,    73,    98,
      94,    91,    72,    73,    85,    86,    87,    95,    72,    73,
     146,    72,    73,   124,     4,   103,    29,    31,    33,   132,
       4,    69,     5,   141,     6,   143,     7,     8,     9,    10,
      11,   111,   110,    13,    14,    15,     5,   100,     6,    29,
      31,    33,     4,     0,     5,     0,     6,   112,     7,     8,
       9,    10,    11,     0,     0,    13,    14,    15,   127,     0,
      16,    17,    18,     5,     0,     6,    35,     0,    36,     0,
      72,    73,     0,   128,    16,    17,    18,     5,   138,     6,
       0,     0,    16,    17,    18,    72,    73,    57,     5,     0,
       6,     0,   129,    35,     0,    36,     0,     0,   130,     0,
     131,    16,    17,    18,    72,    73,     0,    35,     0,    36,
      72,    73,    72,    73,     0,    16,    17,    18,    35,     0,
      36,     0,     0,     0,     0,    63,    16,    17,    18,    64,
      65,    66,    67,    68,    75,    76,    77,    78,    79,    80
  };

  const short
  LoLaParser::yycheck_[] =
  {
       2,     2,     2,    34,    41,     0,    26,    59,     5,    29,
       8,     7,    36,    37,    29,    43,     6,   117,    15,   119,
      41,    42,     5,     5,     7,     8,    41,    42,    19,     6,
      28,    27,    34,    34,    34,     3,   136,     5,    43,     7,
     140,     9,    10,    11,    12,    13,     6,    15,    16,    17,
      18,    88,    35,    43,    37,    52,    53,     6,     6,     5,
      43,    44,    45,    60,    41,    42,    63,    64,    65,    66,
      67,    68,   124,     6,     6,    43,    44,    45,     8,     6,
      28,    41,    42,     5,    43,    29,    29,   118,    29,     5,
      29,    29,    41,    42,    91,    92,    28,    41,    42,     5,
      29,    28,    41,    42,    38,    39,    40,    43,    41,    42,
     141,    41,    42,     5,     3,    43,   118,   118,   118,   116,
       3,     4,     5,    14,     7,    43,     9,    10,    11,    12,
      13,    81,    74,    16,    17,    18,     5,     6,     7,   141,
     141,   141,     3,    -1,     5,    -1,     7,    84,     9,    10,
      11,    12,    13,    -1,    -1,    16,    17,    18,    29,    -1,
      43,    44,    45,     5,    -1,     7,    35,    -1,    37,    -1,
      41,    42,    -1,    29,    43,    44,    45,     5,     6,     7,
      -1,    -1,    43,    44,    45,    41,    42,    29,     5,    -1,
       7,    -1,    29,    35,    -1,    37,    -1,    -1,    29,    -1,
      29,    43,    44,    45,    41,    42,    -1,    35,    -1,    37,
      41,    42,    41,    42,    -1,    43,    44,    45,    35,    -1,
      37,    -1,    -1,    -1,    -1,    26,    43,    44,    45,    30,
      31,    32,    33,    34,    20,    21,    22,    23,    24,    25
  };

  const signed char
  LoLaParser::yystos_[] =
  {
       0,    47,    48,     0,     3,     5,     7,     9,    10,    11,
      12,    13,    15,    16,    17,    18,    43,    44,    45,    49,
      51,    53,    54,    55,    56,    57,    58,    59,    60,    71,
      72,    73,    74,    76,    52,    35,    37,    62,    64,    66,
      68,    69,    70,    71,    73,    76,     8,    62,    75,    43,
      43,     5,     5,     5,    43,    29,    29,    29,    62,     5,
       7,    27,    29,    26,    30,    31,    32,    33,    34,     4,
      53,     6,    41,    42,    61,    20,    21,    22,    23,    24,
      25,    63,    36,    37,    65,    38,    39,    40,    67,    70,
       8,    28,    26,    29,    29,    43,    62,    62,     5,    29,
       6,    75,    62,    43,    62,    62,    62,    62,    62,    62,
      64,    66,    68,    70,    62,    62,    19,     6,     6,     6,
      43,    50,     6,     8,     5,    29,    29,    29,    29,    29,
      29,    29,    62,    51,    53,    51,     6,    28,     6,    75,
       6,    14,    51,    43,     6,    51,    53
  };

  const signed char
  LoLaParser::yyr1_[] =
  {
       0,    46,    47,    48,    48,    48,    49,    49,    50,    50,
      51,    52,    52,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    54,    54,    54,    55,    55,    55,    55,
      55,    55,    56,    57,    58,    58,    59,    59,    60,    61,
      61,    62,    62,    63,    63,    63,    63,    63,    63,    64,
      64,    65,    65,    66,    66,    67,    67,    67,    68,    68,
      69,    69,    70,    70,    71,    71,    71,    72,    72,    72,
      72,    73,    73,    73,    73,    74,    74,    75,    75,    76,
      76
  };

  const signed char
  LoLaParser::yyr2_[] =
  {
       0,     2,     1,     0,     2,     2,     6,     5,     1,     3,
       3,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     5,     3,     3,     4,     4,     4,     4,
       4,     4,     7,     5,     3,     2,     7,     5,     2,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     1,     3,     1,
       1,     1,     2,     1,     3,     1,     1,     1,     1,     1,
       1,     5,     6,     3,     4,     2,     3,     3,     1,     4,
       1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const LoLaParser::yytname_[] =
  {
  "END", "error", "\"invalid token\"", "CURLY_O", "CURLY_C", "ROUND_O",
  "ROUND_C", "SQUARE_O", "SQUARE_C", "VAR", "EXTERN", "FOR", "WHILE", "IF",
  "ELSE", "FUNCTION", "BREAK", "CONTINUE", "RETURN", "IN", "LEQUAL",
  "GEQUAL", "EQUALS", "DIFFERS", "LESS", "MORE", "IS", "DOT", "COMMA",
  "TERMINATOR", "PLUS_IS", "MINUS_IS", "MULT_IS", "DIV_IS", "MOD_IS",
  "INVERT", "PLUS", "MINUS", "MULT", "DIV", "MOD", "AND", "OR", "IDENT",
  "NUMBER", "STRING", "$accept", "compile_unit", "program", "function",
  "plist", "body", "stmtlist", "statement", "decl", "ass", "for", "while",
  "return", "conditional", "expression", "expr_0_op", "expr_0",
  "expr_02_op", "expr_02", "expr_1_op", "expr_1", "expr_2_op", "expr_2",
  "expr_3_op", "expr_3", "expr_4", "rvalue", "call", "array", "arglist",
  "lvalue", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  LoLaParser::yyrline_[] =
  {
       0,    83,    83,    85,    86,    90,    96,   101,   107,   111,
     118,   121,   122,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   140,   141,   142,   145,   146,   147,   148,
     149,   150,   153,   156,   159,   160,   163,   164,   167,   170,
     170,   171,   172,   175,   175,   175,   175,   175,   175,   176,
     177,   181,   181,   182,   183,   187,   187,   187,   188,   189,
     193,   193,   194,   195,   199,   200,   201,   204,   205,   206,
     207,   210,   211,   212,   213,   216,   217,   220,   224,   229,
     230
  };

  void
  LoLaParser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  LoLaParser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  LoLaParser::symbol_kind_type
  LoLaParser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
    };
    const int user_token_number_max_ = 300;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= user_token_number_max_)
      return YY_CAST (symbol_kind_type, translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 5 "grammar.yy"
} // LoLa
#line 2142 "grammar.tab.cpp"

#line 234 "grammar.yy"



void
LoLa::LoLaParser::error( const location_type &l, const std::string &err_message )
{
   std::cerr << "Error: " << err_message << " at " << l << "\n";
}
