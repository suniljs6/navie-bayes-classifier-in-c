# navie-bayes-classifier-in-c


Naive Bayes classifiers are a collection of classification algorithms based on Bayes’ Theorem. It is not a single algorithm but a family of algorithms where all of them share a common principle, i.e. every pair of features being classified is independent of each other.



Assumption:
---

    The fundamental Naive Bayes assumption is that each feature makes an:

        independent
        equal

    contribution to the outcome.

    With relation to our dataset, this concept can be understood as:

        We assume that no pair of features are dependent. For example, the temperature being ‘Hot’ has nothing to do with the humidity or the outlook being ‘Rainy’ has no effect on the winds. Hence, the features are assumed to be independent.
        Secondly, each feature is given the same weight(or importance). For example, knowing only temperature and humidity alone can’t predict the outcome accuratey. None of the attributes is irrelevant and assumed to be contributing equally to the outcome.

    Note: The assumptions made by Naive Bayes are not generally correct in real-world situations. In-fact, the independence assumption is never correct but often works well in practice.

    Now, before moving to the formula for Naive Bayes, it is important to know about Bayes’ theorem.
    
Bayes’ Theorem:-
--

Bayes’ Theorem finds the probability of an event occurring given the probability of another event that has already occurred. Bayes’ theorem is stated mathematically as the following equation:

P(A|B) = \frac{P(B|A) P(A)}{P(B)}

where A and B are events and P(B) ? 0.

    Basically, we are trying to find probability of event A, given the event B is true. Event B is also termed as evidence.
    P(A) is the priori of A (the prior probability, i.e. Probability of event before evidence is seen). The evidence is an attribute value of an unknown instance(here, it is event B).
    P(A|B) is a posteriori probability of B, i.e. probability of event after evidence is seen.

Now, with regards to our dataset, we can apply Bayes’ theorem in following way:

P(y|X) = \frac{P(X|y) P(y)}{P(X)}

where, y is class variable and X is a dependent feature vector (of size n) where:

X = (x_1,x_2,x_3,.....,x_n)

Naive assumption:-
--

Now, its time to put a naive assumption to the Bayes’ theorem, which is, independence among the features. So now, we split evidence into the independent parts.

Now, if any two events A and B are independent, then,

P(A,B) = P(A)P(B)

Hence, we reach to the result:

P(y|x_1,...,x_n) = \frac{ P(x_1|y)P(x_2|y)...P(x_n|y)P(y)}{P(x_1)P(x_2)...P(x_n)}

which can be expressed as:

P(y|x_1,...,x_n) = \frac{P(y)\prod_{i=1}^{n}P(x_i|y)}{P(x_1)P(x_2)...P(x_n)}

Now, as the denominator remains constant for a given input, we can remove that term:

P(y|x_1,...,x_n)\propto P(y)\prod_{i=1}^{n}P(x_i|y)

Now, we need to create a classifier model. For this, we find the probability of given set of inputs for all possible values of the class variable y and pick up the output with maximum probability. This can be expressed mathematically as:

y = argmax_{y} P(y)\prod_{i=1}^{n}P(x_i|y)

So, finally, we are left with the task of calculating P(y) and P(xi | y).

Please note that P(y) is also called class probability and P(xi | y) is called conditional probability.

The different naive Bayes classifiers differ mainly by the assumptions they make regarding the distribution of P(xi | y).

