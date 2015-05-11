# logistic regression model

set.seed(666)
x1 = runif(1000)          # some continuous variables 
z = 1 + 2*x1
pr = 1/(1+exp(-z))         # pass through an inv-logit function
y = rbinom(1000,1,pr)      # bernoulli response variable

df = data.frame(y=y,x0=1,x1=x1)
write.table(df,"data_logistic.txt",row.names=F,col.names = F)
glm( y~x1,data=df,family="binomial")

