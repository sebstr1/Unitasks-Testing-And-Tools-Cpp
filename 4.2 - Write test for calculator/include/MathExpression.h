/*
 * Autor       : Mikael Nilsson
 * Filename    : MathExpression.h
 * Description : Klass för lagring och beräkning av enkla matematiska uttryck.
 *
*/

#ifndef MATHEXPRESSION_H
#define MATHEXPRESSION_H

#include <string>

/*
 * Klass för lagring och beräkning av enkla matematiska uttryck.
 */
class MathExpression
{
public:
    /*
     * Skapar ett MathExpression från en sträng.
     */
    MathExpression(const std::string &expression);

    /*
     * Returnerar en sträng som är identisk med den som gavs till konstruktorn.
     */
    std::string infixNotation() const;

    /*
     * Returnerar en uttrycket på postfix from
     */
    std::string postfixNotation() const;

    /*
     * Beräknar postfix uttrycket och returnerar svaret.
     */
    double calculate() const;

    /*
     * Returnerar falskt om uttrycket är ogiltigt.
     */
    bool isValid() const;

    /*
     * Returnerar ett felmeddelande om uttrycket är falskt.
     */
    std::string errorMessage() const;

    /*
     * Ersätter befintligt uttryck med expression (nollställer objektet).
     */
    MathExpression& operator=(const std::string& expression);
private:

 /* Lägg till privata funktioner och variabler här */

};

#endif // MATHEXPRESSION_H
