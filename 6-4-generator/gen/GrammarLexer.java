// Generated from /home/free0u/ifmo/discrete-labs/6-4-generator/Grammar.g4 by ANTLR 4.x
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class GrammarLexer extends Lexer {
	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__2=1, T__1=2, T__0=3, HEADER=4, MEMBERS=5, SYM=6, RETURN_SYM=7, NONTERM=8, 
		INT=9, TOKEN=10, EPS=11, WS=12;
	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	public static final String[] tokenNames = {
		"<INVALID>",
		"':'", "'|'", "';'", "HEADER", "MEMBERS", "SYM", "RETURN_SYM", "NONTERM", 
		"INT", "TOKEN", "'eps'", "WS"
	};
	public static final String[] ruleNames = {
		"T__2", "T__1", "T__0", "HEADER", "MEMBERS", "ANY", "SYM", "RETURN_SYM", 
		"NONTERM", "INT", "TOKEN", "EPS", "WS"
	};


	public GrammarLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "Grammar.g4"; }

	@Override
	public String[] getTokenNames() { return tokenNames; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u0430\ud6d1\u8206\uad2d\u4417\uaef1\u8d80\uaadd\2\16o\b\1\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\3\2\3\2\3\3\3\3\3\4\3\4\3\5\3\5\3\5\3\5"+
		"\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3"+
		"\6\3\6\3\6\3\6\3\7\7\7>\n\7\f\7\16\7A\13\7\3\b\3\b\7\bE\n\b\f\b\16\bH"+
		"\13\b\3\b\3\b\3\t\3\t\7\tN\n\t\f\t\16\tQ\13\t\3\t\3\t\3\n\6\nV\n\n\r\n"+
		"\16\nW\3\13\6\13[\n\13\r\13\16\13\\\3\f\3\f\6\fa\n\f\r\f\16\fb\3\f\3\f"+
		"\3\r\3\r\3\r\3\r\3\16\6\16l\n\16\r\16\16\16m\6?FOb\2\17\3\3\5\4\7\5\t"+
		"\6\13\7\r\2\17\b\21\t\23\n\25\13\27\f\31\r\33\16\3\2\5\4\2C\\aa\3\2\62"+
		";\5\2\13\f\17\17\"\"t\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2\2"+
		"\2\13\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3\2\2\2\2\25\3\2\2\2\2\27"+
		"\3\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\3\35\3\2\2\2\5\37\3\2\2\2\7!\3\2\2"+
		"\2\t#\3\2\2\2\13/\3\2\2\2\r?\3\2\2\2\17B\3\2\2\2\21K\3\2\2\2\23U\3\2\2"+
		"\2\25Z\3\2\2\2\27^\3\2\2\2\31f\3\2\2\2\33k\3\2\2\2\35\36\7<\2\2\36\4\3"+
		"\2\2\2\37 \7~\2\2 \6\3\2\2\2!\"\7=\2\2\"\b\3\2\2\2#$\7j\2\2$%\7g\2\2%"+
		"&\7c\2\2&\'\7f\2\2\'(\7g\2\2()\7t\2\2)*\7}\2\2*+\3\2\2\2+,\5\r\7\2,-\7"+
		"\177\2\2-.\5\33\16\2.\n\3\2\2\2/\60\7o\2\2\60\61\7g\2\2\61\62\7o\2\2\62"+
		"\63\7d\2\2\63\64\7g\2\2\64\65\7t\2\2\65\66\7u\2\2\66\67\7}\2\2\678\3\2"+
		"\2\289\5\r\7\29:\7\177\2\2:;\5\33\16\2;\f\3\2\2\2<>\13\2\2\2=<\3\2\2\2"+
		">A\3\2\2\2?@\3\2\2\2?=\3\2\2\2@\16\3\2\2\2A?\3\2\2\2BF\7}\2\2CE\13\2\2"+
		"\2DC\3\2\2\2EH\3\2\2\2FG\3\2\2\2FD\3\2\2\2GI\3\2\2\2HF\3\2\2\2IJ\7\177"+
		"\2\2J\20\3\2\2\2KO\7]\2\2LN\13\2\2\2ML\3\2\2\2NQ\3\2\2\2OP\3\2\2\2OM\3"+
		"\2\2\2PR\3\2\2\2QO\3\2\2\2RS\7_\2\2S\22\3\2\2\2TV\t\2\2\2UT\3\2\2\2VW"+
		"\3\2\2\2WU\3\2\2\2WX\3\2\2\2X\24\3\2\2\2Y[\t\3\2\2ZY\3\2\2\2[\\\3\2\2"+
		"\2\\Z\3\2\2\2\\]\3\2\2\2]\26\3\2\2\2^`\7)\2\2_a\13\2\2\2`_\3\2\2\2ab\3"+
		"\2\2\2bc\3\2\2\2b`\3\2\2\2cd\3\2\2\2de\7)\2\2e\30\3\2\2\2fg\7g\2\2gh\7"+
		"r\2\2hi\7u\2\2i\32\3\2\2\2jl\t\4\2\2kj\3\2\2\2lm\3\2\2\2mk\3\2\2\2mn\3"+
		"\2\2\2n\34\3\2\2\2\n\2?FOW\\bm\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}