template<typename Type>
class IteratorVector;

template<typename Type>
class VectorDinamic
{
private:
	Type* elemente;
	int lungime;
	int capacitate;

public:
	friend class IteratorVector<Type>;

	VectorDinamic();
	VectorDinamic(const VectorDinamic& original);
	~VectorDinamic();

	void reset();
	Type& at(int pozitie);
	void push_back(const Type& c);
	size_t size();

	IteratorVector<Type> begin();
	IteratorVector<Type> end();
	void erase(int beginning);
};

template<typename Type>
VectorDinamic<Type>::VectorDinamic()
{
	this->lungime = 0;
	this->capacitate = 10;
	this->elemente = new Type[this->capacitate];
}

template<typename Type>
VectorDinamic<Type>::VectorDinamic(const VectorDinamic& original)
{
	this->elemente = new Type[original.capacitate];
	for (int i = 0; i < original.lungime; i++)
		this->elemente[i] = original.elemente[i];
	this->lungime = original.lungime;
	this->capacitate = original.capacitate;
}

template<typename Type>
VectorDinamic<Type>::~VectorDinamic()
{
	delete[] this->elemente;
}

template<typename Type>
class IteratorVector
{
private:
	const VectorDinamic<Type>& vector;
	int pozitie = 0;
public:
	IteratorVector(const VectorDinamic<Type>& vector);
	IteratorVector(const VectorDinamic<Type>& vector, int pozitie);
	/*bool valid() const;
	Type& element() const;
	void next();
	Type& operator*();
	IteratorVector& operator++();
	bool operator==(const IteratorVector& ot) noexcept;
	bool operator!=(const IteratorVector& ot) noexcept;*/
};

template<typename Type>
Type& VectorDinamic<Type>::at(int pozitie)
{
	return this->elemente[pozitie];
}

template<typename Type>
void VectorDinamic<Type>::push_back(const Type& c)
{
	if (this->lungime == this->capacitate)
	{
		this->capacitate *= 2;
		Type* aux = new Type[this->capacitate];
		for (int i = 0; i < this->lungime; i++)
		{
			aux[i] = this->elemente[i];
		}
		delete[] this->elemente;
		this->elemente = aux;
	}

	this->elemente[this->lungime] = c;
	this->lungime++;
}

template<typename Type>
IteratorVector<Type>::IteratorVector(const VectorDinamic<Type>& vector)
{
	this->vector = vector;
}

template<typename Type>
IteratorVector<Type>::IteratorVector(const VectorDinamic<Type>& vector, int pozitie)
{
	this->vector = vector;
	this->pozitie = pozitie;
}

template<typename Type>
size_t VectorDinamic<Type>::size()
{
	return this->lungime;
}

template<typename Type>
IteratorVector<typename Type> VectorDinamic<Type>::begin()
{
	return IteratorVector<Type>(*this);
}

template<typename Type>
IteratorVector<typename Type> VectorDinamic<Type>::end()
{
	return IteratorVector<Type>(*this, this->lungime);
}

template<typename Type>
void VectorDinamic<Type>::erase(int beginning)
{
	for (int it = beginning; it < this->lungime; it++)
		this->elemente[it] = this->elemente[it + 1];
	lungime--;
}

template<typename Type>
void VectorDinamic<Type>::reset()
{
	delete[] this->elemente;
	this->lungime = 0;
	this->capacitate = 10;
	this->elemente = new Type[this->capacitate];
}
