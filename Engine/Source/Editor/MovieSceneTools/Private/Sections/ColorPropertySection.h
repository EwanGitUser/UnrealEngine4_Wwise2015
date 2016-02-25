// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#pragma once

class UMovieSceneColorSection;

/**
* A color section implementation
*/
class FColorPropertySection
	: public FPropertySection
{
public:

	/**
	 * Create and initialize a new instance.
	 *
	 * @param InSectionObject
	 * @param SectionName The name of the section.
	 * @param InSequencer The sequencer that manages the section.
	 * @param InTrack The track that owns the section.
	 */
	FColorPropertySection(UMovieSceneSection& InSectionObject, ISequencer* InSequencer, UMovieSceneTrack& InTrack)
		: FPropertySection(InSectionObject, InTrack.GetTrackName())
		, Sequencer(InSequencer)
		, Track(*Cast<UMovieSceneColorTrack>(&InTrack))
	{ }

public:

	// FPropertySection interface

	virtual void GenerateSectionLayout(class ISectionLayoutBuilder& LayoutBuilder) const override;
	virtual int32 OnPaintSection(const FGeometry& AllottedGeometry, const FSlateRect& SectionClippingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, bool bParentEnabled) const override;

protected:

	/** Consolidate color curves for all track sections. */
	void ConsolidateColorCurves(TArray< TKeyValuePair<float, FLinearColor> >& OutColorKeys, const UMovieSceneColorSection* Section) const;
	
	/** Find the Slate color of the specified name in the track. */
	FLinearColor FindSlateColor(const FName& ColorName) const;

private:

	/** The sequencer that manages the section. */
	ISequencer* Sequencer;

	/** The track that owns the section. */
	UMovieSceneColorTrack& Track;
};