#ifndef __StreamingStatisticsMosaicFilter_txx
#define __StreamingStatisticsMosaicFilter_txx

#include "otbStreamingStatisticsMosaicFilter.h"

namespace otb {

template <class TInputImage, class TOutputImage, class TInternalValueType>
PersistentStatisticsMosaicFilter<TInputImage, TOutputImage, TInternalValueType>
::PersistentStatisticsMosaicFilter(){

  // allocate the data objects for the outputs which are
  // just decorators around pixel types
  // 1: means
  // 2: stdevs
  // 3: means of products
  // 4: mins
  // 5: maxs
  for (int i = 1; i < 6; ++i)
    {
    typename RealMatrixListObjectType::Pointer output
    = static_cast<RealMatrixListObjectType*>(this->MakeOutput(i).GetPointer());
    this->itk::ProcessObject::SetNthOutput(i, output.GetPointer());
    }

  // allocate the data objects for the outputs which are
  // just decorators around real matrices
  //
  // 6: count
  typename LongMatrixObjectType::Pointer output
  = static_cast<LongMatrixObjectType*>(this->MakeOutput(6).GetPointer());
  this->itk::ProcessObject::SetNthOutput(6, output.GetPointer());

}

/*
 * Make output
 */
template <class TInputImage, class TOutputImage, class TInternalValueType>
typename itk::DataObject::Pointer
PersistentStatisticsMosaicFilter<TInputImage, TOutputImage, TInternalValueType>
::MakeOutput(DataObjectPointerArraySizeType output)
{
  itkDebugMacro( << "Entering MakeOutput(" << output << ")" );
  if (output == 0)
    {
    return static_cast<itk::DataObject*>(TOutputImage::New().GetPointer());
    }
  else if (output == 6)
    {
    return static_cast<itk::DataObject*>(LongMatrixObjectType::New().GetPointer());
    }
  return static_cast<itk::DataObject*>(RealMatrixListObjectType::New().GetPointer());

}

template <class TInputImage, class TOutputImage, class TInternalValueType>
typename PersistentStatisticsMosaicFilter<TInputImage, TOutputImage, TInternalValueType>::RealMatrixListObjectType*
PersistentStatisticsMosaicFilter<TInputImage, TOutputImage, TInternalValueType>
::GetMeansOutput()
{
  return static_cast<RealMatrixListObjectType*>(this->itk::ProcessObject::GetOutput(1));
}

template <class TInputImage, class TOutputImage, class TInternalValueType>
typename PersistentStatisticsMosaicFilter<TInputImage, TOutputImage, TInternalValueType>::RealMatrixListObjectType*
PersistentStatisticsMosaicFilter<TInputImage, TOutputImage, TInternalValueType>
::GetStdsOutput()
{
  return static_cast<RealMatrixListObjectType*>(this->itk::ProcessObject::GetOutput(2));
}

template <class TInputImage, class TOutputImage, class TInternalValueType>
typename PersistentStatisticsMosaicFilter<TInputImage, TOutputImage, TInternalValueType>::RealMatrixListObjectType*
PersistentStatisticsMosaicFilter<TInputImage, TOutputImage, TInternalValueType>
::GetMeansOfProductsOutput()
{
  return static_cast<RealMatrixListObjectType*>(this->itk::ProcessObject::GetOutput(3));
}

template <class TInputImage, class TOutputImage, class TInternalValueType>
typename PersistentStatisticsMosaicFilter<TInputImage, TOutputImage, TInternalValueType>::RealMatrixListObjectType*
PersistentStatisticsMosaicFilter<TInputImage, TOutputImage, TInternalValueType>
::GetMinsOutput()
{
  return static_cast<RealMatrixListObjectType*>(this->itk::ProcessObject::GetOutput(4));
}

template <class TInputImage, class TOutputImage, class TInternalValueType>
typename PersistentStatisticsMosaicFilter<TInputImage, TOutputImage, TInternalValueType>::RealMatrixListObjectType*
PersistentStatisticsMosaicFilter<TInputImage, TOutputImage, TInternalValueType>
::GetMaxsOutput()
{
  return static_cast<RealMatrixListObjectType*>(this->itk::ProcessObject::GetOutput(5));
}

template <class TInputImage, class TOutputImage, class TInternalValueType>
typename PersistentStatisticsMosaicFilter<TInputImage, TOutputImage, TInternalValueType>::LongMatrixObjectType*
PersistentStatisticsMosaicFilter<TInputImage, TOutputImage, TInternalValueType>
::GetAreasOutput()
{
  return static_cast<LongMatrixObjectType*>(this->itk::ProcessObject::GetOutput(6));
}

template <class TInputImage, class TOutputImage, class TInternalValueType>
const typename PersistentStatisticsMosaicFilter<TInputImage, TOutputImage, TInternalValueType>::RealMatrixListObjectType*
PersistentStatisticsMosaicFilter<TInputImage, TOutputImage, TInternalValueType>
::GetMeansOutput() const
{
  return static_cast<const RealMatrixListObjectType*>(this->itk::ProcessObject::GetOutput(1));
}

template <class TInputImage, class TOutputImage, class TInternalValueType>
const typename PersistentStatisticsMosaicFilter<TInputImage, TOutputImage, TInternalValueType>::RealMatrixListObjectType*
PersistentStatisticsMosaicFilter<TInputImage, TOutputImage, TInternalValueType>
::GetStdsOutput() const
{
  return static_cast<const RealMatrixListObjectType*>(this->itk::ProcessObject::GetOutput(2));
}

template <class TInputImage, class TOutputImage, class TInternalValueType>
const typename PersistentStatisticsMosaicFilter<TInputImage, TOutputImage, TInternalValueType>::RealMatrixListObjectType*
PersistentStatisticsMosaicFilter<TInputImage, TOutputImage, TInternalValueType>
::GetMeansOfProductsOutput() const
{
  return static_cast<const RealMatrixListObjectType*>(this->itk::ProcessObject::GetOutput(3));
}

template <class TInputImage, class TOutputImage, class TInternalValueType>
const typename PersistentStatisticsMosaicFilter<TInputImage, TOutputImage, TInternalValueType>::RealMatrixListObjectType*
PersistentStatisticsMosaicFilter<TInputImage, TOutputImage, TInternalValueType>
::GetMinsOutput() const
{
  return static_cast<const RealMatrixListObjectType*>(this->itk::ProcessObject::GetOutput(4));
}

template <class TInputImage, class TOutputImage, class TInternalValueType>
const typename PersistentStatisticsMosaicFilter<TInputImage, TOutputImage, TInternalValueType>::RealMatrixListObjectType*
PersistentStatisticsMosaicFilter<TInputImage, TOutputImage, TInternalValueType>
::GetMaxsOutput() const
{
  return static_cast<const RealMatrixListObjectType*>(this->itk::ProcessObject::GetOutput(5));
}

template <class TInputImage, class TOutputImage, class TInternalValueType>
const typename PersistentStatisticsMosaicFilter<TInputImage, TOutputImage, TInternalValueType>::LongMatrixObjectType*
PersistentStatisticsMosaicFilter<TInputImage, TOutputImage, TInternalValueType>
::GetAreasOutput() const
{
  return static_cast<const LongMatrixObjectType*>(this->itk::ProcessObject::GetOutput(6));
}

/**
 * Reset() implementation
 */
template <class TInputImage, class TOutputImage, class TInternalValueType>
void
PersistentStatisticsMosaicFilter<TInputImage, TOutputImage, TInternalValueType>
::Reset()
 {
  itkDebugMacro( << "Entering Reset()" );

  Superclass::GenerateOutputInformation();

  // Prepare threads result
  const unsigned int numberOfThreads = this->GetNumberOfThreads();
  unsigned int nBands = this->GetNumberOfBands();
  unsigned int nbImages = this->GetNumberOfInputImages();

  itkDebugMacro ( << "\nN threads: " << numberOfThreads <<
      "\nN bands: " << nBands <<
      "\nN images: " << nbImages );

  internalThreadResults.clear();
  for (unsigned int threadId = 0 ; threadId < numberOfThreads ; threadId++)
    {
    // Create a clean empty container for each thread
    ThreadResultsContainer threadResult(nBands,nbImages*nbImages);
    internalThreadResults.push_back(threadResult);
    }

 }

template <class TInputImage, class TOutputImage, class TInternalValueType>
void
PersistentStatisticsMosaicFilter<TInputImage, TOutputImage, TInternalValueType>
::AllocateOutputs()
{
  itkDebugMacro( << "Entering AllocateOutputs()" );
  // This is commented to prevent the streaming of the whole image for the first stream strip
  // It shall not cause any problem because the output image of this filter is not intended to be used.
  //InputImagePointer image = const_cast< TInputImage * >( this->GetInput() );
  //this->GraftOutput( image );
  // Nothing that needs to be allocated for the remaining outputs
}

/*
 * Synthetize() implementation
 */
template <class TInputImage, class TOutputImage, class TInternalValueType>
void
PersistentStatisticsMosaicFilter<TInputImage, TOutputImage, TInternalValueType>
::Synthetize()
{
  itkDebugMacro( << "Entering Synthetize()" );

  unsigned int nBands = Superclass::GetNumberOfBands();
  unsigned int nbImages = this->GetNumberOfInputImages();
  const unsigned int numberOfThreads = this->GetNumberOfThreads();

  // Merge threads result
  ThreadResultsContainer finalResults = ThreadResultsContainer(nBands,nbImages*nbImages);
  for (unsigned int threadId = 0 ; threadId < numberOfThreads ; threadId++)
    {
    finalResults.Update(internalThreadResults.at(threadId) );
    }

  // Compute final outputs
  m_Means.clear();
  m_Stds.clear();
  m_ProdMeans.clear();
  m_Mins.clear();
  m_Maxs.clear();
  m_Area = LongMatrixType(nbImages,nbImages,0);

  for (unsigned int band = 0 ; band < nBands ; band++)
    {
    RealMatrixType mean    (nbImages, nbImages, 0);
    RealMatrixType prodmean(nbImages, nbImages, 0);
    RealMatrixType stdev   (nbImages, nbImages, 0);
    RealMatrixType min     (nbImages, nbImages, itk::NumericTraits<InputImageInternalPixelType>::max() );
    RealMatrixType max     (nbImages, nbImages, itk::NumericTraits<InputImageInternalPixelType>::NonpositiveMin() );

    for (unsigned int i = 0 ; i < nbImages ; i++)
      {
      for (unsigned int j = 0 ; j < nbImages ; j++)
        {

        long              count    = finalResults.m_count[i*nbImages+j];
        InternalValueType sum      = finalResults.m_sum[band][i*nbImages+j];
        InternalValueType cosum    = finalResults.m_cosum[band][i*nbImages+j];
        InternalValueType sqSum    = finalResults.m_sqSum[band][i*nbImages+j];
        InternalValueType minValue = finalResults.m_min[band][i*nbImages+j];
        InternalValueType maxValue = finalResults.m_max[band][i*nbImages+j];

        // Update area
        m_Area[i][j] = count;

        // Update Min and Max
        if (minValue < min[i][j])
          min[i][j] = minValue;
        if (maxValue > max[i][j])
          max[i][j] = maxValue;

        // Update Mean, Std and Mean of products
        if (count > 0)
          {
          mean[i][j]      = sum   / (static_cast<InternalValueType>(count) );
          prodmean[i][j]  = cosum / (static_cast<InternalValueType>(count) );
          // Unbiased estimate
          InternalValueType variance = (sqSum - (sum*sum
              / static_cast<InternalValueType>(count) ) )
                    / (static_cast<InternalValueType>(count) - 1);
          if (variance > 0)
            {
            stdev[i][j] = vcl_sqrt(variance);
            }

          }
        }
      }
    m_Means.push_back(mean);
    m_Stds.push_back(stdev);
    m_ProdMeans.push_back(prodmean);
    m_Mins.push_back(min);
    m_Maxs.push_back(max);

    } // next band

  this->GetMeansOutput()->Set(m_Means);
  this->GetStdsOutput()->Set(m_Stds);
  this->GetMeansOfProductsOutput()->Set(m_ProdMeans);
  this->GetMinsOutput()->Set(m_Mins);
  this->GetMaxsOutput()->Set(m_Maxs);
  this->GetAreasOutput()->Set(m_Area);
}

/**
 * Processing
 */
template <class TInputImage, class TOutputImage, class TInternalValueType>
void
PersistentStatisticsMosaicFilter<TInputImage, TOutputImage, TInternalValueType>
::ThreadedGenerateData(const OutputImageRegionType& outputRegionForThread, itk::ThreadIdType threadId)
{

  // Debug info
  itkDebugMacro(<<"Actually executing thread " << threadId << " in region " << outputRegionForThread);

  // Support progress methods/callbacks
  itk::ProgressReporter progress(this, threadId, outputRegionForThread.GetNumberOfPixels() );

  // Get number of input images
  const unsigned int nbOfInputImages = this->GetNumberOfInputImages();

  // Get number of used inputs
  const unsigned int nbOfUsedInputImages = Superclass::GetNumberOfUsedInputImages();

  // Iterate through the thread region
  IteratorType outputIt(this->GetOutput(), outputRegionForThread);

  // Prepare input pointers, interpolators, and valid regions (input images)
  typename std::vector<InputImageType *>        currentImage;
  typename std::vector<InterpolatorPointerType> interp;
  Superclass::PrepareImageAccessors(currentImage, interp);

  // temporary variables
  OutputImagePointType geoPoint;

  for ( outputIt.GoToBegin(); !outputIt.IsAtEnd(); ++outputIt )
    {

    // Update progress
    progress.CompletedPixel();

    // Overlap descriptor for the current pixel (yes/no + value)
    std::vector<unsigned int>        overlapImagesIndices;
    std::vector<InputImagePixelType> overlapPixelValue;

    // Current pixel --> Geographical point
    this->GetOutput()->TransformIndexToPhysicalPoint (outputIt.GetIndex(), geoPoint) ;

    // Loop on used input images
    for (unsigned int i = 0 ; i < nbOfUsedInputImages ; i++)
      {

      // Check if the point is inside the transformed thread region
      // (i.e. the region in the current input image which match the thread
      // region)
      if (interp[i]->IsInsideBuffer(geoPoint) )
        {

        // Compute the interpolated pixel value
        InputImagePixelType interpolatedPixel = interp[i]->Evaluate(geoPoint);

        // Put image index + image pixel value into memory
        if (Superclass::IsPixelNotEmpty(interpolatedPixel) )
          {
          overlapImagesIndices.push_back (Superclass::GetUsedInputImageIndice(i) );
          overlapPixelValue.push_back(interpolatedPixel);
          }

        } // point inside buffer
      }   // next image

    // Update thread result

    // Nb of overlaps at the current pixel
    unsigned int nbOfOverlappingPixels = overlapImagesIndices.size();

    // Loop on overlapping pixels
    for (unsigned int i = 0 ; i < nbOfOverlappingPixels ; i++)
      {
      // Index of the image whose comes the current overlapping pixel
      unsigned int imageIndex = overlapImagesIndices.at(i);

      // We need to sum this pixel to all overlaps ij
      InputImagePixelType pixel = overlapPixelValue.at(i);

      for (unsigned int j = 0 ; j < nbOfOverlappingPixels ; j++)
        {
        //				if (i!=j)
          {
          // Index of the other image which share this overlapping pixel
          unsigned int otherImageIndex = overlapImagesIndices.at(j);

          // Pixel value of the other image which share this overlapping pixel
          InputImagePixelType otherPixel = overlapPixelValue.at(j);

          // Update
          internalThreadResults.at(threadId).Update(pixel, otherPixel, imageIndex*nbOfInputImages + otherImageIndex);
          }
        }
      } // loop on overlapping pixels

    } // next output pixel

}

} // end namespace gtb

#endif
