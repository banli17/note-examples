const States = {
  Initial: 1,
  Identifier: 2,
  IntLiteral: 3,
  GT: 4,
  GE: 5,
  Int: 6,
  Assignment: 7,
  Identifier_int1: 8,
  Identifier_int2: 9,
};

const TokenType = {
  Identifier: 2,
  IntLiteral: 3,
  GT: 4,
  GE: 5,
  Int: 6,
  Assignment: 7,
};

class Tokenizer {
  constructor() {
    this.state = States.Initial;
    this.tokens = [];
    this.token = "";
    this.tokenType = null;
  }

  emitToken(ch) {
    if (this.tokenType) {
      this.tokens.push([this.tokenType, this.token]);
    }
    this.state = States.Initial; // 恢复成初始状态
    this.tokenType = null;
    this.token = "";

    this.nextToken(ch);
  }

  start(ch) {
    if (this.isAlpha(ch)) {
      if (ch === "i") {
        this.state = States.Identifier_int1;
      } else {
        this.state = States.Identifier;
      }
      this.tokenType = TokenType.Identifier;
      this.token += ch;
    } else if (this.isDigit(ch)) {
      this.state = States.IntLiteral;
      this.tokenType = TokenType.IntLiteral;
      this.token += ch;
    } else if (ch === ">") {
      this.state = States.GT;
      this.tokenType = TokenType.GT;
      this.token += ch;
    } else if (ch === "=") {
      this.state = States.Assignment;
      this.tokenType = TokenType.Assignment;
      this.token += ch;
    }
  }

  nextToken(ch) {
    const { state } = this;
    if (this.state === States.Int) {
      if (this.isAlpha(ch)) {
        this.state = States.Identifier;
        this.token += ch;
      } else {
        this.tokenType = TokenType.Int;
        this.emitToken(ch);
      }
    } else if (this.state === States.Identifier_int2) {
      if (ch === "t") {
        this.token += ch;
        this.state = States.Int;
      } else if (this.isAlpha(ch)) {
        this.state = States.Identifier;
      } else {
        this.emitToken(ch);
      }
    } else if (this.state === States.Identifier_int1) {
      if (ch === "n") {
        this.token += ch;
        this.state = States.Identifier_int2;
      } else if (this.isAlpha(ch)) {
        this.token += ch;
        this.state = States.Identifier;
      } else {
        this.emitToken(ch);
      }
    } else if (this.state === States.Identifier) {
      if (this.isAlpha(ch) || this.isDigit(ch)) {
        this.token += ch;
      } else {
        this.emitToken(ch);
      }
    } else if (this.state === States.GT) {
      if (ch === "=") {
        this.token += ch;
        this.state = States.GE;
      } else {
        this.emitToken(ch);
      }
    } else if (this.state === States.IntLiteral) {
      if (this.isDigit(ch)) {
        this.token += ch;
      } else {
        this.emitToken(ch);
      }
    } else if (this.state === States.GE) {
      this.emitToken(ch);
    } else if (this.state === States.Assignment) {
      this.emitToken(ch);
    } else if (this.state === States.Initial) {
      this.start(ch);
    }
  }

  isAlpha(ch) {
    return /[a-zA-z]/.test(ch);
  }

  isDigit(ch) {
    return /[0-9]/.test(ch);
  }

  parse(source) {
    // console.log("source", source);
    let i = 0;
    let len = source.length;

    while (i < len) {
      const ch = source[i];
      this.nextToken(ch);
      i++;
    }
    return this.tokens;
  }

  static parse(source) {
    return new Tokenizer().parse(source);
  }
}

/**
 * 词法规则
 */

export default Tokenizer;
