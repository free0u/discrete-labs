// Generated from /home/free0u/ifmo/discrete-labs/6-4-generator/Grammar.g4 by ANTLR 4.x
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class GrammarParser extends Parser {
	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__2=1, T__1=2, T__0=3, HEADER=4, MEMBERS=5, SYM=6, RETURN_SYM=7, NONTERM=8, 
		INT=9, TOKEN=10, EPS=11, WS=12;
	public static final String[] tokenNames = {
		"<INVALID>", "':'", "'|'", "';'", "HEADER", "MEMBERS", "SYM", "RETURN_SYM", 
		"NONTERM", "INT", "TOKEN", "'eps'", "WS"
	};
	public static final int
		RULE_start = 0, RULE_rules = 1, RULE_rule_ = 2, RULE_rrule = 3, RULE_terms = 4;
	public static final String[] ruleNames = {
		"start", "rules", "rule_", "rrule", "terms"
	};

	@Override
	public String getGrammarFileName() { return "Grammar.g4"; }

	@Override
	public String[] getTokenNames() { return tokenNames; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public GrammarParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}
	public static class StartContext extends ParserRuleContext {
		public RulesContext rules() {
			return getRuleContext(RulesContext.class,0);
		}
		public TerminalNode HEADER() { return getToken(GrammarParser.HEADER, 0); }
		public TerminalNode MEMBERS() { return getToken(GrammarParser.MEMBERS, 0); }
		public StartContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_start; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof GrammarListener ) ((GrammarListener)listener).enterStart(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof GrammarListener ) ((GrammarListener)listener).exitStart(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof GrammarVisitor ) return ((GrammarVisitor<? extends T>)visitor).visitStart(this);
			else return visitor.visitChildren(this);
		}
	}

	public final StartContext start() throws RecognitionException {
		StartContext _localctx = new StartContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_start);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(11);
			_la = _input.LA(1);
			if (_la==HEADER) {
				{
				setState(10); match(HEADER);
				}
			}

			setState(14);
			_la = _input.LA(1);
			if (_la==MEMBERS) {
				{
				setState(13); match(MEMBERS);
				}
			}

			setState(16); rules();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class RulesContext extends ParserRuleContext {
		public List<Rule_Context> rule_() {
			return getRuleContexts(Rule_Context.class);
		}
		public Rule_Context rule_(int i) {
			return getRuleContext(Rule_Context.class,i);
		}
		public RulesContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_rules; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof GrammarListener ) ((GrammarListener)listener).enterRules(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof GrammarListener ) ((GrammarListener)listener).exitRules(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof GrammarVisitor ) return ((GrammarVisitor<? extends T>)visitor).visitRules(this);
			else return visitor.visitChildren(this);
		}
	}

	public final RulesContext rules() throws RecognitionException {
		RulesContext _localctx = new RulesContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_rules);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(19); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(18); rule_();
				}
				}
				setState(21); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( _la==NONTERM );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Rule_Context extends ParserRuleContext {
		public RruleContext rrule(int i) {
			return getRuleContext(RruleContext.class,i);
		}
		public TerminalNode WS() { return getToken(GrammarParser.WS, 0); }
		public List<RruleContext> rrule() {
			return getRuleContexts(RruleContext.class);
		}
		public TerminalNode RETURN_SYM() { return getToken(GrammarParser.RETURN_SYM, 0); }
		public TerminalNode NONTERM() { return getToken(GrammarParser.NONTERM, 0); }
		public Rule_Context(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_rule_; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof GrammarListener ) ((GrammarListener)listener).enterRule_(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof GrammarListener ) ((GrammarListener)listener).exitRule_(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof GrammarVisitor ) return ((GrammarVisitor<? extends T>)visitor).visitRule_(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Rule_Context rule_() throws RecognitionException {
		Rule_Context _localctx = new Rule_Context(_ctx, getState());
		enterRule(_localctx, 4, RULE_rule_);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(23); match(NONTERM);
			setState(25);
			_la = _input.LA(1);
			if (_la==RETURN_SYM) {
				{
				setState(24); match(RETURN_SYM);
				}
			}

			setState(27); match(1);
			setState(28); rrule();
			setState(33);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==2) {
				{
				{
				setState(29); match(2);
				setState(30); rrule();
				}
				}
				setState(35);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(36); match(3);
			setState(37); match(WS);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class RruleContext extends ParserRuleContext {
		public List<TermsContext> terms() {
			return getRuleContexts(TermsContext.class);
		}
		public TermsContext terms(int i) {
			return getRuleContext(TermsContext.class,i);
		}
		public RruleContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_rrule; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof GrammarListener ) ((GrammarListener)listener).enterRrule(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof GrammarListener ) ((GrammarListener)listener).exitRrule(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof GrammarVisitor ) return ((GrammarVisitor<? extends T>)visitor).visitRrule(this);
			else return visitor.visitChildren(this);
		}
	}

	public final RruleContext rrule() throws RecognitionException {
		RruleContext _localctx = new RruleContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_rrule);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(40); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(39); terms();
				}
				}
				setState(42); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( (((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << SYM) | (1L << NONTERM) | (1L << TOKEN) | (1L << EPS) | (1L << WS))) != 0) );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class TermsContext extends ParserRuleContext {
		public TerminalNode WS() { return getToken(GrammarParser.WS, 0); }
		public TerminalNode EPS() { return getToken(GrammarParser.EPS, 0); }
		public TerminalNode SYM() { return getToken(GrammarParser.SYM, 0); }
		public TerminalNode TOKEN() { return getToken(GrammarParser.TOKEN, 0); }
		public TerminalNode NONTERM() { return getToken(GrammarParser.NONTERM, 0); }
		public TermsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_terms; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof GrammarListener ) ((GrammarListener)listener).enterTerms(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof GrammarListener ) ((GrammarListener)listener).exitTerms(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof GrammarVisitor ) return ((GrammarVisitor<? extends T>)visitor).visitTerms(this);
			else return visitor.visitChildren(this);
		}
	}

	public final TermsContext terms() throws RecognitionException {
		TermsContext _localctx = new TermsContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_terms);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(44);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << SYM) | (1L << NONTERM) | (1L << TOKEN) | (1L << EPS) | (1L << WS))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			consume();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static final String _serializedATN =
		"\3\u0430\ud6d1\u8206\uad2d\u4417\uaef1\u8d80\uaadd\3\16\61\4\2\t\2\4\3"+
		"\t\3\4\4\t\4\4\5\t\5\4\6\t\6\3\2\5\2\16\n\2\3\2\5\2\21\n\2\3\2\3\2\3\3"+
		"\6\3\26\n\3\r\3\16\3\27\3\4\3\4\5\4\34\n\4\3\4\3\4\3\4\3\4\7\4\"\n\4\f"+
		"\4\16\4%\13\4\3\4\3\4\3\4\3\5\6\5+\n\5\r\5\16\5,\3\6\3\6\3\6\2\2\7\2\4"+
		"\6\b\n\2\3\5\2\b\b\n\n\f\16\61\2\r\3\2\2\2\4\25\3\2\2\2\6\31\3\2\2\2\b"+
		"*\3\2\2\2\n.\3\2\2\2\f\16\7\6\2\2\r\f\3\2\2\2\r\16\3\2\2\2\16\20\3\2\2"+
		"\2\17\21\7\7\2\2\20\17\3\2\2\2\20\21\3\2\2\2\21\22\3\2\2\2\22\23\5\4\3"+
		"\2\23\3\3\2\2\2\24\26\5\6\4\2\25\24\3\2\2\2\26\27\3\2\2\2\27\25\3\2\2"+
		"\2\27\30\3\2\2\2\30\5\3\2\2\2\31\33\7\n\2\2\32\34\7\t\2\2\33\32\3\2\2"+
		"\2\33\34\3\2\2\2\34\35\3\2\2\2\35\36\7\3\2\2\36#\5\b\5\2\37 \7\4\2\2 "+
		"\"\5\b\5\2!\37\3\2\2\2\"%\3\2\2\2#!\3\2\2\2#$\3\2\2\2$&\3\2\2\2%#\3\2"+
		"\2\2&\'\7\5\2\2\'(\7\16\2\2(\7\3\2\2\2)+\5\n\6\2*)\3\2\2\2+,\3\2\2\2,"+
		"*\3\2\2\2,-\3\2\2\2-\t\3\2\2\2./\t\2\2\2/\13\3\2\2\2\b\r\20\27\33#,";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}