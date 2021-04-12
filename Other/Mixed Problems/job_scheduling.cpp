/*
    Implement Job Scheduling using Max Priority Queues. 
    The node of the priority queue will be a class having Job number and priority. 
    Priority should be the key value. It should be a menu driven program that provides following options :
    a. Insert a new job (Input will be job no and priority)
    b. delete an existing job 
    c. increase priority of existing job (input- job no and new priority)
    d. decrease priority of existing job (input- job no and new priority)
    e. extract job with highest priority.
*/

#include <iostream>
#include <limits>
#include <vector>
using namespace std;

#define NOTFOUND(job_no) "Job with job _no: " + to_string(job_no) + " does not exist."
#define EMPTY_PLACEHOLDER "Job list is empty"

struct Job
{
    int job_no;
    int pri_of_job;
};

class PQ // priority queue
{
private:
    vector<struct Job> max_heap;

    // helper functions
    int parent(int ind);             // parent
    int left(int ind);               // left child
    int right(int ind);              // right child
    int search(int job_no);          // search job | return index
    void swap(Job &obj1, Job &obj2); // swaping
    void upHeapify(int ind);
    void maxHeapify(int ind);

public:
    bool empty();                                 // check max_heap is empty or not
    void insert(Job obj);                         // Insert new job
    void deleteJob(int job_no);                   // delete an existing job
    void increasePri(int job_no, int pri_of_job); // increase priority of existing job
    void decresePri(int job_no, int pri_of_job);  // decrease priority of existing job
    Job extractPriJob();                          // extract job with highest priority
    void display();                               // display jobs
};

int PQ::parent(int ind)
{
    return (ind - 1) / 2;
}

int PQ::left(int ind)
{
    return (2 * ind + 1);
}

int PQ::right(int ind)
{
    return (2 * ind + 2);
}

int PQ::search(int job_no)
{
    for (int i = 0; i < max_heap.size(); i++)
    {
        if (max_heap[i].job_no == job_no)
            return i; // if job_no exist
    }

    return -1; // if job_no does not exist
}

void PQ::swap(Job &obj1, Job &obj2)
{
    Job temp = obj1;
    obj1 = obj2;
    obj2 = temp;
}

void PQ::upHeapify(int ind)
{
    while (ind != 0 &&
           max_heap[parent(ind)].pri_of_job < max_heap[ind].pri_of_job)
    {
        swap(max_heap[parent(ind)], max_heap[ind]);
        ind = parent(ind);
    }
}

void PQ::maxHeapify(int ind)
{
    int lt = left(ind), rt = right(ind);
    int largest = ind;
    int size = max_heap.size();

    if (lt < size &&
        max_heap[lt].pri_of_job > max_heap[largest].pri_of_job)
    {
        largest = lt;
    }

    if (rt < size &&
        max_heap[rt].pri_of_job > max_heap[largest].pri_of_job)
    {
        largest = rt;
    }

    if (largest != ind)
    {
        swap(max_heap[largest], max_heap[ind]);
        maxHeapify(largest);
    }
}

bool PQ::empty()
{
    return (max_heap.size() <= 0);
}

void PQ::insert(Job obj)
{
    max_heap.push_back(obj);
    upHeapify(max_heap.size() - 1);
    cout << "\nInserted Successfully !!";
}

void PQ::deleteJob(int job_no)
{
    increasePri(job_no, numeric_limits<int>::max());
    extractPriJob();
}

void PQ::increasePri(int job_no, int pri_of_job)
{
    int ind = search(job_no);

    if (ind == -1)
    {
        cout << '\n'
             << NOTFOUND(job_no) << '\n';
    }
    else
    {
        if (max_heap[ind].pri_of_job > pri_of_job)
        {
            cout << "\nNew priority " << pri_of_job
                 << "is not greated than " << max_heap[ind].pri_of_job;
        }
        else
        {
            max_heap[ind].pri_of_job = pri_of_job;
            upHeapify(ind);
            cout << "\nIncreased Successfully !!";
        }
    }
}

void PQ::decresePri(int job_no, int pri_of_job)
{
    int ind = search(job_no);

    if (ind == -1)
    {
        cout << '\n'
             << NOTFOUND(job_no) << '\n';
    }
    else
    {
        if (max_heap[ind].pri_of_job < pri_of_job)
        {
            cout << "\nNew priority " << pri_of_job
                 << "is not less than " << max_heap[ind].pri_of_job;
        }
        else
        {
            max_heap[ind].pri_of_job = pri_of_job;
            maxHeapify(ind);
            cout << "\nDecreased Successfully !!";
        }
    }
}

Job PQ::extractPriJob()
{
    Job result = max_heap[0];

    if (!max_heap.empty()) // if max_heap is not empty
    {
        Job temp = max_heap.back();
        max_heap.pop_back();
        max_heap[0] = temp;
        maxHeapify(0);
    }

    return result;
}

void PQ::display()
{
    for (int i = 0; i < max_heap.size(); i++)
    {
        cout << "\nJob " << i + 1 << ":\n"
             << "job no. : " << max_heap[i].job_no << '\n'
             << "priority of job : " << max_heap[i].pri_of_job
             << '\n';
    }
}

// menu for the program
void menu()
{
    cout << "\n\nChoose An Option : "
         << "\n1. Insert a new job"
         << "\n2. Delete an existing job"
         << "\n3. Increase priority of existing job"
         << "\n4. Decrease priority of existing job"
         << "\n5. Extract job with highest priority."
         << "\n6. Display jobs"
         << "\n7. Want to quit!";
}

int main()
{
    PQ pq; // priority queue
    int choice;

    while (choice != 7)
    {
        menu();
        cout << "\n\nEnter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Job job;
            cout << "\nEnter job no. : ";
            cin >> job.job_no;

            cout << "\nEnter priority no. : ";
            cin >> job.pri_of_job;

            pq.insert(job);
        }
        break;

        case 2:
        {
            if (pq.empty())
            {
                cout << '\n'
                     << EMPTY_PLACEHOLDER;
            }
            else
            {
                int jbn;
                cout << "\nEnter job no. : ";
                cin >> jbn;
                pq.deleteJob(jbn);
            }
        }
        break;

        case 3:
        {
            if (pq.empty())
            {
                cout << '\n'
                     << EMPTY_PLACEHOLDER;
            }
            else
            {
                int jbn, prn;
                cout << "\nEnter job no. : ";
                cin >> jbn;
                cout << "\nEnter new priority no. : ";
                cin >> prn;

                pq.increasePri(jbn, prn);
            }
        }
        break;

        case 4:
        {
            if (pq.empty())
            {
                cout << '\n'
                     << EMPTY_PLACEHOLDER;
            }
            else
            {
                int jbn, prn;
                cout << "\nEnter job no. : ";
                cin >> jbn;
                cout << "\nEnter new priority no. : ";
                cin >> prn;

                pq.decresePri(jbn, prn);
            }
        }
        break;

        case 5:
        {
            if (pq.empty())
            {
                cout << '\n'
                     << EMPTY_PLACEHOLDER;
            }
            else
            {
                Job jb = pq.extractPriJob();
                cout << "\nExtracted Job : "
                     << "\njob no. : " << jb.job_no
                     << "\npri no. : " << jb.pri_of_job;
            }
        }
        break;

        case 6:
        {
            if (pq.empty())
            {
                cout << '\n'
                     << EMPTY_PLACEHOLDER;
            }
            else
            {
                cout << "\nJob Lists : \n";
                pq.display();
            }
        }
        break;

        case 7:
            break;

        default:
            cout << "\nChoose the right option !!!";
            break;
        }
    }

    return 0;
}
