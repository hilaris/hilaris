#include <cppunit/Exception.h>
#include <cppunit/SourceLine.h>
#include <cppunit/TestFailure.h>
#include <cppunit/TestResultCollector.h>
#include "HilarisOutputter.h"

CPPUNIT_NS_BEGIN

HilarisOutputter::HilarisOutputter(TestResultCollector *result, OStream &stream) : m_result( result ), m_stream( stream ) {}
HilarisOutputter::~HilarisOutputter() {}

void 
HilarisOutputter::write() 
{
  printHeader();
  m_stream << "\n";
  printFailures();
  m_stream << "\n";
}


void 
HilarisOutputter::printFailures()
{
  TestResultCollector::TestFailures::const_iterator itFailure = m_result->failures().begin();
  int failureNumber = 1;
  while ( itFailure != m_result->failures().end() ) 
  {
    m_stream  <<  "\n";
    printFailure( *itFailure++, failureNumber++ );
  }
}


void 
HilarisOutputter::printFailure( TestFailure *failure,
                             int failureNumber )
{
  printFailureListMark( failureNumber );
  m_stream << ' ';
  printFailureTestName( failure );
  m_stream << ' ';
  printFailureType( failure );
  m_stream << ' ';
  printFailureLocation( failure->sourceLine() );
  m_stream << "\n";
  printFailureDetail( failure->thrownException() );
  m_stream << "\n";
}


void 
HilarisOutputter::printFailureListMark( int failureNumber )
{
  m_stream << failureNumber << ")";
}


void 
HilarisOutputter::printFailureTestName( TestFailure *failure )
{
  m_stream << "test: " << failure->failedTestName();
}


void 
HilarisOutputter::printFailureType( TestFailure *failure )
{
  m_stream << "("
           << (failure->isError() ? "E" : "F")
           << ")";
}


void 
HilarisOutputter::printFailureLocation( SourceLine sourceLine )
{
  if ( !sourceLine.isValid() )
    return;

  m_stream << "line: " << sourceLine.lineNumber()
           << ' ' << sourceLine.fileName();
}


void 
HilarisOutputter::printFailureDetail( Exception *thrownException )
{
  m_stream  <<  thrownException->message().shortDescription()  <<  "\n";
  m_stream  <<  thrownException->message().details();
}


void 
HilarisOutputter::printHeader()
{
if(m_result->wasSuccessful())
{
	m_stream << "\033[1mI\'m the \"Everything\'s Fine\" unicorn!\033[0m\n\n            \\ \n             \\ \n             _\\^\n           _- oo\\\n           \\---- \\______\n                 \\       )\\\n                ||-----||  \\\n                ||     ||\n";
}
//  m_stream << "\033[1mOK (\033[0m" << m_result->runTests () << " tests)\n" ;
else
{
m_stream << "\n";
printFailureWarning();
printStatistics();
}
}


void HilarisOutputter::printFailureWarning()
{ 
	m_stream << "   \033[1mFix those errors, or you will be sent directly to hell!\033[0m\n                                                                    _\n                                                                  _( (~\\\n           _ _                        /                          ( \\> > \\\n       -/~/ / ~\\                     :;                \\       _  > /(~\\/\n      || | | /\\ ;\\                   |l      _____     |;     ( \\/    > >\n      _\\\\)\\)\\)/ ;;;                  `8o __-~     ~\\   d|      \\      //\n     ///(())(__/~;;\\                  \"88p;.  -. _\\_;.oP        (_._/ /\n    (((__   __ \\\\   \\                  `>,% (\\  (\\./)8\"         ;:'  i\n    )))--`.'-- (( ;,8 \\               ,;%%%:  ./V^^^V'          ;.   ;.\n    ((\\   |   /)) .,88  `: ..,,;;;;,-::::::'_::\\   ||\\         ;[8:   ;\n     )|  ~-~  |(|(888; ..``'::::8888oooooo.  :\\`^^^/,,~--._    |88::  |\n     |\\ -===- /|  \\8;; ``:.      oo.8888888888:`((( o.ooo8888Oo;:;:'  |\n     |_~-___-~_|   `-\\.   `        `o`88888888b` )) 888b88888P\"\"'     ;\n     ; ~~~~;~~         \"`--_`.       b`888888888;(.,\"888b888\"  ..::;-'\n       ;      ;              ~\"-....  b`8888888:::::.`8888. .:;;;''\n          ;    ;                 `:::. `:::OOO:::::::.`OO' ;;;''\n     :       ;                     `.      \"``::::::''    .'\n        ;                           `.   \\_              /\n      ;       ;                       +:   ~~--  `:'  -';\n                                       `:         : .::/\n          ;                            ;;+_  :::. :..;;;\n                                       ;;;;;;,;;;;;;;;,;\n\n";
}


void 
HilarisOutputter::printStatistics()
{
  m_stream  << "Test Results:\n";

  m_stream  <<  "Run:  "  <<  m_result->runTests()
            <<  "   Failures: "  <<  m_result->testFailures()
            <<  "   Errors: "  <<  m_result->testErrors()
            <<  "\n";
}


CPPUNIT_NS_END

