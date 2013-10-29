//#include <DbManager.h>
#include<sqlca.h>
#include <iostream>

using namespace std;

using namespace oracle::occi;

const string sqlString("select empno, ename, hiredate from emp");

const string dateFormat("DD-MON-YYYY HH24:MI:SS");

int main(int argc, char **argv)

{
    if (argc != 2)
    {
        cerr << "\nUsage: " << argv[0] << " <db-user-name>\n" << endl;
        exit(1);
    }
    
    // Initialize OracleServices
    
    DbManager* dbm = NULL;
    
    OracleServices* oras = NULL;
    
    Statement *stmt = NULL;
    
    ResultSet *resultSet = NULL;
    
    try
    {
        
        // Obtain OracleServices object with the default args.
        
        dbm = new DbManager(userName);
        
        oras = dbm->getOracleServices();
        
        // Obtain a cached connection
        
        Connection * conn = oras->connection();
        
        // Create a statement
        
        stmt = conn->createStatement(sqlString);
        
        int empno;
        
        string ename;
        
        Date hireDate;
        
        string dateAsString;
        
        // Execute query to get a resultset
        
        resultSet = stmt->executeQuery();
        
        while (resultSet->next())
        {
            
            empno = resultSet->getInt(1);  // get the first column returned by the query;
            
            ename = resultSet->getString(2);  // get the second column returned by the query
            
            hireDate = resultSet->getDate(3);  // get the third column returned by the query
            
            dateAsString="";
            
            //You cannot check for null until the data has been read
            
            if (resultSet->isNull(1))
            {
                cout << "Employee num is null... " << endl;
            }
            if (resultSet->isNull(2))
            {
                cout << "Employee name is null..." << endl;
            }
            if (resultSet->isNull(3))
            {
                cout << "Hire date is null..." << endl;
            }
            else
            {
                dateAsString=hireDate.toText(dateFormat);
            }
            cout << empno << "\t" << ename << "\t" << dateAsString << endl;
            
        }
        
        // Close ResultSet and Statement
        
        stmt->closeResultSet(resultSet);
        
        conn->terminateStatement(stmt);
        
        // Close Connection and OCCI Environment
        
        delete dbm;
        
    }
    catch (SQLException& ex)
    {
        if (dbm != NULL)
        {
            dbm->rollbackActions(ex, stmt, resultSet); // free resources and rollback transaction
        }
    }
    catch (ExoException& ex1)
    {
        cerr << "\nCaught ExoException:\n" << ex1.getExceptionText() << endl;
        exit(2);
    }
    
    return 0;
}